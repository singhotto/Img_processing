#include "Image.hh"

// Default constructor
Image::Image() : data(nullptr), width(0), height(0), channels(0) {}

// Parameterized constructor for initializing with existing data
Image::Image(unsigned char* data, int width, int height, int channels) 
    : data(nullptr), width(width), height(height), channels(channels) {
    // Allocate memory for the image data
    if (data != nullptr) {
        throw std::runtime_error("Failed to load image!");
    } 
    this->data = data;
}

// Destructor
Image::~Image() {
    clear();
}

// Copy constructor
Image::Image(const Image& other) 
    : width(other.width), height(other.height), channels(other.channels) {
    if (other.data) {
        data = new unsigned char[width * height * channels];
        std::copy(other.data, other.data + (width * height * channels), data);
    } else {
        data = nullptr;
    }
}

// Copy assignment operator
Image& Image::operator=(const Image& other) {
    if (this != &other) { // Check for self-assignment
        clear(); // Free existing resources

        width = other.width;
        height = other.height;
        channels = other.channels;

        if (other.data) {
            data = new unsigned char[width * height * channels];
            std::copy(other.data, other.data + (width * height * channels), data);
        } else {
            data = nullptr;
        }
    }
    return *this;
}

// Move constructor
Image::Image(Image&& other) noexcept 
    : data(other.data), width(other.width), height(other.height), channels(other.channels) {
    other.data = nullptr; // Leave the moved-from object in a valid state
    other.width = other.height = other.channels = 0;
}

// Move assignment operator
Image& Image::operator=(Image&& other) noexcept {
    if (this != &other) { // Check for self-assignment
        clear(); // Free existing resources

        // Transfer ownership of resources
        data = other.data;
        width = other.width;
        height = other.height;
        channels = other.channels;

        // Leave the moved-from object in a valid state
        other.data = nullptr;
        other.width = other.height = other.channels = 0;
    }
    return *this;
}

int Image::getWidth() const
{
    return 0;
}

int Image::getHeight() const
{
    return 0;
}

int Image::getChannels() const
{
    return 0;
}

const unsigned char *Image::getData() const
{
    return nullptr;
}

// Method to clear the image data
void Image::clear() {
    if (data) {
        delete data; 
        data = nullptr;
    }
}
