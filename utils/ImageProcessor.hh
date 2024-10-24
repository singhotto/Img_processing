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
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    Image rgb2Grayscale(const Image& image);
    Image toBinary(const Image& image, int threshold = 150);
    Image changeBrightness(const Image& image, int threshold);
    void generateHistogram(const Image& image);
};

#endif