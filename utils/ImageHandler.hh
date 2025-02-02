#ifndef IMAGE_HANDLER_GUARD
#define IMAGE_HANDLER_GUARD

#include "Image.hh"
#include <string>
#include <stdexcept> 

class ImageHandler {
private:
    // Private constructor to prevent instantiation
    ImageHandler();

    // Delete copy constructor and assignment operator to avoid copies
    ImageHandler(const ImageHandler&) = delete;
    ImageHandler& operator=(const ImageHandler&) = delete;

public:
    // Static method to access the singleton instance
    static ImageHandler& getInstance();

    // Load an image from file into an Image object
    Image loadImage(const std::string& filename);

    // Save the Image object to a file
    void saveImage(const std::string& filename, Image& image);
};
#endif