#include "ImageProcessor.hh"

#define WHITE 255
#define BLACK 0

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void swap(float& a, float& b){
    float c = a;
    a = b;
    b = c;
}

std::vector<float> ImageProcessor::getHistogram(const Image &img)
{
    std::vector<float> hist(256, 0);

    float *data = img.getData();
    int size = img.getChannels() * img.getHeight() * img.getWidth();
    for (int i = 0; i < size; i++)
    {
        hist[(int)data[i]]++;
    }

    for (float &f : hist)
    {
        f = f / size;
    }

    return hist;
}

void ImageProcessor::rotateImage(Image &img, char x)
{
    int originalH = img.getHeight();
    int originalW = img.getWidth();
    int width = originalW;
    int height = originalH;
    int cnls = img.getChannels();

    if (x == 'l' || x == 'r')
    {
        swap(width, height);
    }

    Image newImage(img.getName(), width, height, cnls, img.getType(), img.getBPC());

    float *oldData = img.getData();
    float *newData = newImage.getData();

    if (x == 'r')
    {
        for (int i = 0; i < height; i++)
        {
            int newRowPointer = i * width;
            for (int j = 0; j < width; j++)
            {
                int pointerOld = ((originalH - j - 1) * originalW + i) * cnls;
                int pointerNew = (newRowPointer + j) * cnls;

                for (int k = 0; k < cnls; k++)
                {
                    newData[pointerNew + k] = oldData[pointerOld + k];
                }
            }
        }
    }

    if (x == 'l')
    {
        for (int i = 0; i < height; i++)
        {
            int newRowPointer = i * width;
            for (int j = 0; j < width; j++)
            {
                int pointerOld = (j * originalW + originalH - i - 1) * cnls;
                int pointerNew = (newRowPointer + j) * cnls;

                for (int k = 0; k < cnls; k++)
                {
                    newData[pointerNew + k] = oldData[pointerOld + k];
                }
            }
        }
    }

    if (x == 'd')
    {
        for (int i = 0; i < height; i++)
        {
            int oldRowPointer = (originalH - i - 1) * originalW;
            int newRowPointer = i * width;
            for (int j = 0; j < width; j++)
            {
                int pointerOld = (oldRowPointer + originalW- j -1) * cnls;
                int pointerNew = (newRowPointer + j) * cnls;

                for (int k = 0; k < cnls; k++)
                {
                    newData[pointerNew + k] = oldData[pointerOld + k];
                }
            }
        }
    }

    img = newImage;
}

void ImageProcessor::mirror(Image &img, char x)
{
    int width = img.getWidth();
    int height = img.getHeight();
    int cnls = img.getChannels();
    float *data = img.getData();

    if (x == 'x')
    {
        for (int i = 0; i < height/2; i++)
        {
            int pointerRA = i * width;
            int pointerRB = (height - i - 1) * width;
            for (int j = 0; j < width; j++)
            {
                int pointerA = (pointerRA + j) * cnls;
                int pointerB = (pointerRB + j) * cnls;

                for (int k = 0; k < cnls; k++)
                {
                    swap(data[pointerA], data[pointerB]);
                }
            }
        }
    }

    if (x == 'y')
    {
        for (int i = 0; i < height; i++)
        {
            int pointerRA = i * width;
            int pointerRB = pointerRA + width; 
            for (int j = 0; j < width/2; j++)
            {

                int pointerA = (pointerRA + j) * cnls;
                int pointerB = (pointerRB + width - j - 1) * cnls;
                for (int k = 0; k < cnls; k++)
                {
                    swap(data[pointerA + k], data[pointerB+k]);
                }
            }
        }
    }
}

float min(float a, float b)
{
    float res = a < b ? a : b;
    return res;
}

float max(float a, float b)
{
    float res = a > b ? a : b;
    return res;
}

ImageProcessor::ImageProcessor() {}

ImageProcessor &ImageProcessor::getInstance()
{
    static ImageProcessor instance; // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

void ImageProcessor::rgb2Grayscale(Image &image)
{
    int channels = image.getChannels();
    if (channels < 3)
        throw std::runtime_error("It's not a color Image!!!");

    int alpha = image.getData()[4];
    int size = image.getWidth() * image.getHeight();

    float *data = image.getData();

    for (int i = 0; i < size; i++)
    {
        int idx1 = i * channels;
        int idx2 = i * channels + 1;
        int idx3 = i * channels + 2;
        float temp = data[idx1] * 0.299f + data[idx2] * 0.587f + data[idx3] * 0.114f;
        data[idx1] = temp;
        data[idx2] = temp;
        data[idx3] = temp;
        if (channels == 4)
        {
            data[i * channels + 3] = alpha;
        }
    }
}

void ImageProcessor::toBinary(Image &image, int threshold)
{
    int channels = image.getChannels();
    int size = image.getWidth() * image.getHeight();

    float *data = image.getData();

    if (channels < 3)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = data[i] > threshold ? WHITE : BLACK;
        }
    }
    else
    {
        int alpha = image.getData()[4];

        for (int i = 0; i < size; i++)
        {
            int idx1 = i * channels;
            int idx2 = i * channels + 1;
            int idx3 = i * channels + 2;
            float temp = data[idx1] * 0.299f + data[idx2] * 0.587f + data[idx3] * 0.114f;
            temp = temp > threshold ? WHITE : BLACK;
            data[idx1] = temp;
            data[idx2] = temp;
            data[idx3] = temp;
            if (channels == 4)
            {
                data[i * channels + 3] = alpha;
            }
        }
    }
}

void ImageProcessor::changeBrightness(Image &image, int threshold)
{
    int channels = image.getChannels();
    int size = image.getWidth() * image.getHeight();

    float *data = image.getData();

    if (channels < 3)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = data[i] + threshold;
            if (data[i] > WHITE)
                data[i] = WHITE;
            if (data[i] < BLACK)
                data[i] = BLACK;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int idx1 = i * channels;
            int idx2 = i * channels + 1;
            int idx3 = i * channels + 2;

            data[idx1] = min(WHITE, max(BLACK, data[idx1] + threshold));
            data[idx2] = min(WHITE, max(BLACK, data[idx2] + threshold));
            data[idx3] = min(WHITE, max(BLACK, data[idx3] + threshold));
        }
    }
}

void ImageProcessor::histEqualization(Image &image)
{
    std::vector<float> hist = getHistogram(image);
    std::vector<int> histEq(256, 0);

    float sum = 0.0f;
    int size = image.getChannels() * image.getHeight() * image.getWidth();
    float *data = image.getData();

    for (int i = 0; i < 256; i++)
    {
        sum += hist[i];
        histEq[i] = sum * 255 + 0.5;
    }

    for (int i = 0; i < size; i++)
    {
        data[i] = histEq[(int)data[i]];
    }
}

void ImageProcessor::rotateLeft(Image &image)
{
    rotateImage(image, 'l');
}

void ImageProcessor::rotateRight(Image &image)
{
    rotateImage(image, 'r');
}

void ImageProcessor::rotateDown(Image &image)
{
    rotateImage(image, 'd');
}

void ImageProcessor::negativeImage(Image &image)
{
    float *data = image.getData();
    int height = image.getHeight();
    int width = image.getWidth();
    int cnls = image.getChannels();
    int work_cnls = image.getChannels() < 4?image.getChannels():3;

    for (int i = 0; i < height; i++)
    {
        int newRowPointer = i * width;
        for (int j = 0; j < width; j++)
        {
            int pointer = (newRowPointer + j) * cnls;

            for (int k = 0; k < work_cnls; k++)
            {
                data[pointer + k] = 255.0f - data[pointer + k];
            }
        }
    }
}

void ImageProcessor::mirrorX(Image &image)
{
    mirror(image, 'x');
}

void ImageProcessor::mirrorY(Image &image)
{
    mirror(image, 'y');
}

void ImageProcessor::generateHistogram(const Image &image)
{
    std::vector<float> hist = getHistogram(image);

    std::vector<std::string> labels;
    labels.reserve(255);

    for (int i = 0; i < 256; i++)
    {
        labels.push_back(std::to_string(i));
    }

    Chart chart(hist, labels);

    chart.drawAxes();

    chart.drawBars({0, 100, 200});
    chart.drawXLabels({255, 10, 50});

    chart.writeBMP("../histogram/output.bmp");
}
