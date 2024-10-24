#ifndef IMAGE_GUARD
#define IMAGE_GUARD

#include "../lib/stb_image.h"
#include "../lib/stb_image_write.h"

#include "ImageType.hh"

#include <iostream>
#include <string>

class Image {
private:
    std::string filePath;
    float* data;
    int width;
    int height;
    int channels;
    int bitPerChannel;
    ImageType imageType;

public:
    // Default constructor
    Image();
    Image(const std::string filepath, float* data, int width, int height, int channels, ImageType type, int bitsPerChannel);

    // Destructor
    ~Image();

    // Copy constructor
    Image(const Image& other);

    // Copy assignment operator
    Image& operator=(const Image& other);

    // Move constructor
    Image(Image&& other) noexcept;

    // Move assignment operator
    Image& operator=(Image&& other) noexcept;

    // Getters for image properties
    int getWidth() const;
    int getHeight() const;
    int getChannels() const;
    float* getData() const;
    ImageType getType() const;
    int getBPC() const;
    std::string getName() const;

    float* operator()(int row, int col);
    
    // Method to cfloate data
    void clear();
    void displayInfo() const;
};

#endif // IMAGE_GUARD
