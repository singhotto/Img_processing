#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

#include "Image.hh"

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

    Image rgb2Color(const Image& image);
};

#endif