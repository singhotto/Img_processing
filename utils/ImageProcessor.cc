#include "ImageProcessor.hh"

#define WHITE 255
#define BLACK 0

std::string replaceExtension(const std::string &filename, const std::string &newExtension)
{
    // Find the last dot in the filename
    std::size_t dotPos = filename.find_last_of('.');

    if (dotPos != std::string::npos)
    {
        // Replace the extension
        return filename.substr(0, dotPos + 1) + newExtension;
    }
    else
    {
        // No extension found, just append the new one
        return filename + newExtension;
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

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void swap(float &a, float &b)
{
    float c = a;
    a = b;
    b = c;
}

float gauss(float x, float y, int sigma)
{
    int sigma2 = sigma * sigma;

    return (1 / (2 * M_PI * sigma2)) * exp(-(x * x + y * y) / (2 * sigma2));
}

void calculateKernel(float *kernel, int size, int sigma)
{
    int center = size / 2;
    float sum = 0.0f;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int x = i - center;
            int y = j - center;
            float res = gauss(x, y, sigma);
            kernel[i * size + j] = res;
            sum += res;
        }
    }

    for (int i = 0; i < size * size; i++)
    {
        kernel[i] /= sum;
    }
}

void applykernel(Image &img, float *kernel, int ksize)
{
    int height = img.getHeight();
    int width = img.getWidth();
    float *data = img.getData();
    int cnls = img.getChannels();
    int work_cnls = cnls < 4 ? cnls : 3;
    int offset = ksize / 2;
    float *sumArr = new float[work_cnls];
    memset(sumArr, 0.0f, work_cnls * sizeof(float));

    for (int i = offset; i < height - offset; i++)
    {
        for (int j = offset; j < width - offset; j++)
        {
            for (int k = 0; k < ksize; k++)
            {
                int kRowIdx = k * ksize;
                for (int l = 0; l < ksize; l++)
                {
                    int kIdx = (kRowIdx + l);
                    int idx = ((i + k - offset) * width + (j + l - offset)) * cnls;
                    float kk = kernel[kIdx];

                    for (int m = 0; m < work_cnls; m++)
                        sumArr[m] += data[idx + m] * kk;
                }
            }

            int ii = (i * width + j) * cnls;
            for (int m = 0; m < work_cnls; m++)
                data[ii + m] = sumArr[m];

            memset(sumArr, 0.0f, work_cnls * sizeof(float));
        }
    }

    delete[] sumArr;
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
        swap(width, height);

    Image newImage(img.getName(), width, height, cnls, img.getType(), img.getBPC());

    if (x == 'r')
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Pixel oldPixel = img(originalH - j - 1, i);
                Pixel newPixel = newImage(i, j);

                newPixel.set(oldPixel);
            }
        }
    }

    if (x == 'l')
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Pixel oldPixel = img(j, originalH - i - 1);
                Pixel newPixel = newImage(i, j);

                newPixel.set(oldPixel);
            }
        }
    }

    if (x == 'd')
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Pixel oldPixel = img(originalH - i - 1, originalW - j - 1);
                Pixel newPixel = newImage(i, j);

                newPixel.set(oldPixel);
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
        for (int i = 0; i < height / 2; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Pixel oldPixel = img(i, j);
                Pixel newPixel = img((height - i - 1), j);

                newPixel.swap(oldPixel);
            }
        }
    }

    if (x == 'y')
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width / 2; j++)
            {
                Pixel oldPixel = img(i, j);
                Pixel newPixel = img(i, width - j - 1);

                newPixel.swap(oldPixel);
            }
        }
    }
}

void ImageProcessor::grayscale2color(Image &image, char x)
{
    int cnls = 3;
    int height = image.getHeight();
    int width = image.getWidth();
    float v1, v2, v3;
    int imgCnls = image.getChannels();

    if (x == 'a')
        cnls = 4;

    if (imgCnls == cnls)
        return;

    std::string name = image.getName();
    ImageType imageType = image.getType();
    if (x == 'a')
    {
        name = replaceExtension(image.getName(), "png");
        imageType = ImageType::PNG;
    }

    Image newImage(name, width, height, cnls, imageType, image.getBPC());

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel p = image(i, j);
            v1 = p.getR();
            if(imgCnls >= 3){
                v2 = p.getG();
                v3 = p.getB();
            }
            Pixel np = newImage(i, j);
            if (cnls == 3)
            {
                np.setRGB(v1, v2, v3);
            }
            else
            {
                np.setRGB(v1, v2, v3, 255.0f);
            }
        }
    }

    image = newImage;
}

ImageProcessor::ImageProcessor() {}

ImageProcessor &ImageProcessor::getInstance()
{
    static ImageProcessor instance; // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

void ImageProcessor::conv2Grayscale(Image &image)
{
    if (image.getChannels() < 3)
    {
        std::cout << "It's not a color Image!!!\n";
        return;
    }

    float temp;

    for (int i = 0; i < image.getHeight(); i++)
    {
        for (int j = 0; j < image.getWidth(); j++)
        {
            Pixel pixel = image(i, j);
            temp = pixel.getR() * 0.299f + pixel.getG() * 0.587f + pixel.getB() * 0.114f;
            pixel.setAll(temp);
        }
    }
}

void ImageProcessor::conv2rgb(Image &image)
{
    grayscale2color(image, 'c');
}

void ImageProcessor::conv2rgba(Image &image)
{
    grayscale2color(image, 'a');
}

void ImageProcessor::toBinary(Image &image, int threshold)
{
    int cnls = image.getChannels();
    float temp, v;
    for (int i = 0; i < image.getHeight(); i++)
    {
        for (int j = 0; j < image.getWidth(); j++)
        {
            Pixel pixel = image(i, j);
            if (cnls == 1)
            {
                v = pixel.getR() > threshold ? WHITE : BLACK;
                pixel.setValue(v);
            }
            else
            {
                temp = pixel.getR() * 0.299f + pixel.getG() * 0.587f + pixel.getB() * 0.114f;
                v = temp > threshold ? WHITE : BLACK;
                pixel.setAll(v);
            }
        }
    }
}

void ImageProcessor::setIntensity(Image &image, const float intensity)
{
    if (image.getChannels() != 4)
        throw std::runtime_error("It's not a four channel image!!!");

    for (int i = 0; i < image.getHeight(); i++)
    {
        for (int j = 0; j < image.getWidth(); j++)
        {
            Pixel p = image(i, j);
            p.setAlpha(intensity);
        }
    }
}

void ImageProcessor::changeBrightness(Image &image, int threshold)
{
    int cnls = image.getChannels();
    float r, g, b;
    for (int i = 0; i < image.getHeight(); i++)
    {
        for (int j = 0; j < image.getWidth(); j++)
        {
            Pixel pixel = image(i, j);
            if (cnls == 1)
            {
                r = min(WHITE, max(BLACK, pixel.getR() + threshold));
                pixel.setValue(r);
            }
            else
            {
                r = min(WHITE, max(BLACK, pixel.getR() + threshold));
                g = min(WHITE, max(BLACK, pixel.getG() + threshold));
                b = min(WHITE, max(BLACK, pixel.getB() + threshold));
                pixel.setRGB(r, g, b);
            }
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

Image ImageProcessor::cropImage(Image &image, int x, int y, int sizeX, int sizeY)
{
    if (x < 0 || y < 0 || sizeX > image.getWidth() || sizeY > image.getHeight() || x > image.getWidth() || y > image.getHeight() || (x+sizeX)>image.getWidth() || (y+sizeY)> image.getHeight())
        throw std::runtime_error("Out of bounds!!!");
    Image newImage(image.getName(), sizeX, sizeY, image.getChannels(), image.getType(), image.getBPC());

    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            Pixel oldPixel = image(i + x, j + y);
            Pixel newPixel = newImage(i, j);

            newPixel.set(oldPixel);
        }
    }

    return newImage;
}

Image ImageProcessor::overlayImage(Image background, Image foreground, int row, int col)
{
    int bh = background.getHeight();
    int bw = background.getWidth();
    int fh = foreground.getHeight();
    int fw = foreground.getWidth();

    if(row > bh || col > bw)
        throw std::runtime_error("out of bounds!!!");

    conv2rgba(background);
    conv2rgba(foreground);

    int endBH = min(bh - row, fh);
    int endBW = min(bw - col, fw);
    float alphaB, alphaF;
    float r, g, b, a;

    for(int i = row; i<endBH+row; i++){
        for(int j = col; j<endBW+col; j++){
            Pixel pb = background(i, j);
            Pixel pf = foreground(i-row, j-col);

            alphaB = pb.getA()/255.0f;
            alphaF = pf.getA()/255.0f;

            r = pf.getR() * alphaF + (1.0f - alphaF) * alphaB * pb.getR();
            g = pf.getG() * alphaF + (1.0f - alphaF) * alphaB * pb.getG();
            b = pf.getB() * alphaF + (1.0f - alphaF) * alphaB * pb.getB();
            a = alphaF + (1.0f - alphaF) * alphaB;
            pb.setRGB(r/a, g/a, b/a, a * 255.0f);
        }
    }
    

    return background;
}

void ImageProcessor::negativeImage(Image &image)
{
    int height = image.getHeight();
    int width = image.getWidth();
    int cnls = image.getChannels();
    const float c = 255.0f;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel pixel = image(i, j);
            if (cnls == 1)
            {
                pixel.setValue(c - pixel.getR());
            }
            else
            {
                pixel.setRGB(c - pixel.getR(), c - pixel.getG(), c - pixel.getB());
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

void ImageProcessor::medianFilter(Image &image, int sigma)
{
    if (sigma % 2 == 0)
    {
        sigma += 1;
    }

    int offset = sigma / 2;
    int height = image.getHeight();
    int width = image.getWidth();
    float *data = image.getData();
    int cnls = image.getChannels();

    int work_cnls = cnls < 4 ? cnls : 3;
    std::vector<std::vector<float>> window(work_cnls, std::vector<float>());

    for (int i = 0; i < work_cnls; i++)
    {
        window[i].reserve(sigma * sigma);
    }

    for (int i = offset; i < height - offset; i++)
    {
        for (int j = offset; j < width - offset; j++)
        {
            for (int ik = -offset; ik < offset + 1; ik++)
            {
                int rowPointer = (i + ik) * width;
                for (int jk = -offset; jk < offset + 1; jk++)
                {
                    int pointer = (rowPointer + j + jk) * cnls;
                    for (int m = 0; m < work_cnls; m++)
                    {
                        std::vector<float> *curr = &window[m];
                        curr->push_back(data[pointer + m]);
                    }
                }
            }

            int pp = (i * width + j) * cnls;
            for (int m = 0; m < work_cnls; m++)
            {
                std::vector<float> *curr = &window[m];

                sort(curr->begin(), curr->end());

                data[pp + m] = curr->at(curr->size() / 2);
                curr->clear();
            }
        }
    }
}

void ImageProcessor::gaussianSmoothing(Image &image, int sigma)
{
    int kernelSize = 6 * sigma + 1;

    float *kernel = new float[kernelSize * kernelSize];

    calculateKernel(kernel, kernelSize, sigma);

    applykernel(image, kernel, kernelSize);

    delete[] kernel;
}

void ImageProcessor::addSaltPepper(Image &image, float ratio)
{
    if (ratio > 1.0f)
    {
        ratio = 1.0f;
    }
    int height = image.getHeight();
    int width = image.getWidth();
    float *data = image.getData();
    int cnls = image.getChannels();
    int work_cnls = cnls < 4 ? cnls : 3;
    int noisyPixels = ratio * height * width;
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < noisyPixels; i++)
    {
        int y = rand() % height;
        int x = rand() % width;
        bool salt = rand() % 2;
        int pointer = (y * width + x) * cnls;

        for (int j = 0; j < work_cnls; j++)
        {
            data[pointer + j] = salt ? WHITE : BLACK;
        }
    }
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
