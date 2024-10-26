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
    void rotateImage(Image& img, char x);

    void mirror(Image& img, char x);
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    void rgb2Grayscale(Image& image);
    void toBinary(Image& image, int threshold = 150);
    void changeBrightness(Image& image, int threshold);
    void histEqualization(Image& image);
    
    void rotateLeft(Image& image);
    void rotateRight(Image& image);
    void rotateDown(Image& image);

    void negativeImage(Image& image);

    void mirrorX(Image& image);
    void mirrorY(Image& image);

    //save historgram
    void generateHistogram(const Image& image);
};

#endif