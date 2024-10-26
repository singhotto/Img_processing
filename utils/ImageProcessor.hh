#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

#include "Image.hh"
#include "ChartGenerator/Chart.hh"
#include <vector>
#include <string>
#include <stdexcept> 

class ImageProcessor
{
private:
    // Private constructor to prevent instantiation
    ImageProcessor();

    // Delete copy constructor and assignment operator to avoid copies
    ImageProcessor(const ImageProcessor&) = delete;
    ImageProcessor& operator=(const ImageProcessor&) = delete;

    std::vector<float> getHistogram(const Image& img);
    Image rotateImage(const Image& img, char x);
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    Image rgb2Grayscale(const Image& image);
    Image toBinary(const Image& image, int threshold = 150);
    Image changeBrightness(const Image& image, int threshold);
    Image histEqualization(const Image& image);
    Image rotateLeft(const Image& image);
    Image rotateRight(const Image& image);
    Image rotateDown(const Image& image);
    Image negativeImage(const Image& image);

    //save historgram
    void generateHistogram(const Image& image);
};

#endif