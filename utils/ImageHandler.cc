#include "ImageHandler.hh"

// Constructor definition
ImageHandler::ImageHandler() {}

// Static method to get the singleton instance
ImageHandler& ImageHandler::getInstance() {
    static ImageHandler instance;  // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

// Load an image from file into an Image object
Image ImageHandler::loadImage(const std::string& filename) {
    int width;
    int height;
    int channels;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    return Image(data, width, height, channels);
}

// Save the Image object to a file
void ImageHandler::saveImage(const std::string& filename, const Image& image) {
    if (image.getData() == nullptr) {
        throw std::runtime_error("No image data to save."); // Throw exception if no image data is present
    }

    // Save as PNG (change to other formats if needed)
    if (!stbi_write_png(filename.c_str(), image.getWidth(), image.getHeight(), image.getChannels(), image.getData(), image.getWidth() * image.getChannels())) {
        throw std::runtime_error("Failed to save image: " + filename); // Throw exception if saving fails
    }
}
