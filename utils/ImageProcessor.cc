#include "ImageProcessor.hh"

#define WHITE 255
#define BLACK 0

void swap(int &a, int &b)
{
    int c = a;
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

Image ImageProcessor::rotateImage(const Image &img, char x)
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
                int pointerOld = (j * originalW + i) * cnls;
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
                int pointerOld = (oldRowPointer + j) * cnls;
                int pointerNew = (newRowPointer + j) * cnls;

                for (int k = 0; k < cnls; k++)
                {
                    newData[pointerNew + k] = oldData[pointerOld + k];
                }
            }
        }
    }

    return newImage;
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

Image ImageProcessor::rgb2Grayscale(const Image &image)
{
    int channels = image.getChannels();
    if (channels < 3)
        throw std::runtime_error("It's not a color Image!!!");

    int alpha = image.getData()[4];
    int size = image.getWidth() * image.getHeight();

    Image tempImage = image;

    float *oldData = image.getData();
    float *newdata = tempImage.getData();

    for (int i = 0; i < size; i++)
    {
        int idx1 = i * channels;
        int idx2 = i * channels + 1;
        int idx3 = i * channels + 2;
        float temp = oldData[idx1] * 0.299f + oldData[idx2] * 0.587f + oldData[idx3] * 0.114f;
        newdata[idx1] = temp;
        newdata[idx2] = temp;
        newdata[idx3] = temp;
        if (channels == 4)
        {
            newdata[i * channels + 3] = alpha;
        }
    }

    return tempImage;
}

Image ImageProcessor::toBinary(const Image &image, int threshold)
{
    int channels = image.getChannels();
    int size = image.getWidth() * image.getHeight();

    Image tempImage = image;

    float *oldData = image.getData();
    float *newdata = tempImage.getData();

    if (channels < 3)
    {
        for (int i = 0; i < size; i++)
        {
            newdata[i] = oldData[i] > threshold ? WHITE : BLACK;
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
            float temp = oldData[idx1] * 0.299f + oldData[idx2] * 0.587f + oldData[idx3] * 0.114f;
            temp = temp > threshold ? WHITE : BLACK;
            newdata[idx1] = temp;
            newdata[idx2] = temp;
            newdata[idx3] = temp;
            if (channels == 4)
            {
                newdata[i * channels + 3] = alpha;
            }
        }
    }

    return tempImage;
}

Image ImageProcessor::changeBrightness(const Image &image, int threshold)
{
    int channels = image.getChannels();
    int size = image.getWidth() * image.getHeight();

    Image tempImage = image;

    float *oldData = image.getData();
    float *newdata = tempImage.getData();

    if (channels < 3)
    {
        for (int i = 0; i < size; i++)
        {
            newdata[i] = oldData[i] + threshold;
            if (newdata[i] > WHITE)
                newdata[i] = WHITE;
            if (newdata[i] < BLACK)
                newdata[i] = BLACK;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int idx1 = i * channels;
            int idx2 = i * channels + 1;
            int idx3 = i * channels + 2;

            newdata[idx1] = min(WHITE, max(BLACK, oldData[idx1] + threshold));
            newdata[idx2] = min(WHITE, max(BLACK, oldData[idx2] + threshold));
            newdata[idx3] = min(WHITE, max(BLACK, oldData[idx3] + threshold));
        }
    }

    return tempImage;
}

Image ImageProcessor::histEqualization(const Image &image)
{
    std::vector<float> hist = getHistogram(image);
    std::vector<int> histEq(256, 0);

    Image newImage = image;
    float sum = 0.0f;
    int size = image.getChannels() * image.getHeight() * image.getWidth();
    float *data = image.getData();
    float *newData = newImage.getData();

    for (int i = 0; i < 256; i++)
    {
        sum += hist[i];
        histEq[i] = sum * 255 + 0.5;
    }

    for (int i = 0; i < size; i++)
    {
        newData[i] = histEq[(int)data[i]];
    }

    return newImage;
}

Image ImageProcessor::rotateLeft(const Image &image)
{
    return rotateImage(image, 'l');
}

Image ImageProcessor::rotateRight(const Image &image)
{
    return rotateImage(image, 'r');
}

Image ImageProcessor::rotateDown(const Image &image)
{
    return rotateImage(image, 'd');
}

Image ImageProcessor::negativeImage(const Image &image)
{
    Image newImage = image;
    float *originData = image.getData();
    float *newData = newImage.getData();
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
                newData[pointer + k] = 255.0f - originData[pointer + k];
            }
        }
    }

    return newImage;
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
