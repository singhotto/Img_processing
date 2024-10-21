#ifndef IMAGE_HANDLER_GUARD
#define IMAGE_HANDLER_GUARD


// Include stb_image.h only once
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"
#endif // STB_IMAGE_IMPLEMENTATION

// Include stb_image_write.h only once
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"
#endif // STB_IMAGE_WRITE_IMPLEMENTATION


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
    void saveImage(const std::string& filename, const Image& image);
};
#endif