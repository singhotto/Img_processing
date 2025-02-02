#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

#include "Image.hh"
#include "Pixel.hh"
#include "ChartGenerator/Chart.hh"
#include <vector>
#include <string>
#include <stdexcept> 
#include <cmath>
#include <algorithm>
#include <cstdlib> 
#include <ctime> 

class ImageProcessor
{
private:
    // Private constructor to prevent instantiation
    ImageProcessor();

    // Delete copy constructor and assignment operator to avoid copies
    ImageProcessor(const ImageProcessor&) = delete;
    ImageProcessor& operator=(const ImageProcessor&) = delete;

    std::vector<float> getHistogram(const Image& img);
    void rotateImage(Image& img, char x);

    void mirror(Image& img, char x);
    void grayscale2color(Image& image, char x);
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    void conv2Grayscale(Image& image);
    void conv2rgb(Image& image);
    void conv2rgba(Image& image);

    void toBinary(Image& image, int threshold = 150);
    void setIntensity(Image& image, const float intensity);
    void changeBrightness(Image& image, int threshold);
    void histEqualization(Image& image);
    
    void rotateLeft(Image& image);
    void rotateRight(Image& image);
    void rotateDown(Image& image);

    void mirrorX(Image& image);
    void mirrorY(Image& image);

    Image cropImage(Image& image, int x, int y, int sizeX, int sizeY);

    Image overlayImage(Image a, Image b, int row = 0, int col = 0);

    void negativeImage(Image& image);

    void medianFilter(Image& image, int sigma);
    void gaussianSmoothing(Image& image, int sigma);

    void addSaltPepper(Image& image, float ratio);

    //save historgram
    void generateHistogram(const Image& image);
};

#endif