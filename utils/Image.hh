#ifndef IMAGE_GUARD
#define IMAGE_GUARD

#include <iostream>
#include "../lib/stb_image.h"

class Image {
private:
    unsigned char* data;
    int width;
    int height;
    int channels;

public:
    // Default constructor
    Image();
    Image(unsigned char* data, int width, int height, int channels);

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
    const unsigned char* getData() const;
    
    // Method to clear the image data
    void clear();
};

#endif // IMAGE_GUARD
