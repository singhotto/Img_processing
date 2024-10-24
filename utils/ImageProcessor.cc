#include "ImageProcessor.hh"

#define WHITE 255
#define BLACK 0

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

void ImageProcessor::generateHistogram(const Image &image)
{
    std::vector<float> ihist(256, 0);

    float* data = image.getData();

    for(int i = 0; i<image.getChannels() * image.getHeight() * image.getWidth(); i++){
        ihist[(int)data[i]]++;
    }

    std::vector<std::string> labels;
    labels.reserve(255);

    for(int i = 0; i<256; i++){
        labels.push_back(std::to_string(i));
    }

    Chart chart(ihist, labels);

    chart.drawAxes();

    chart.drawBars({0, 100, 200});
    chart.drawXLabels({255, 10, 50});

    chart.writeBMP("../histogram/output.bmp");
}
