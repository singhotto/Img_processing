#include "Image.hh"

// Default constructor
Image::Image() : data(nullptr), width(0), height(0), channels(0) {}

// Parameterized constructor for initializing with existing data
Image::Image(const std::string filepath, float *data, int width, int height, int channels, ImageType type)
    : filePath(filepath), data(nullptr), width(width), height(height), channels(channels), imageType(type)
{
    // Allocate memory for the image data
    if (data == nullptr)
    {
        throw std::runtime_error("Failed to load image!");
    }
    this->data = data;
}

// Destructor
Image::~Image()
{
    clear();
}

// Copy constructor
Image::Image(const Image &other)
    : width(other.width), height(other.height), channels(other.channels)
{
    if (other.data)
    {
        data = new float[width * height * channels];
        std::copy(other.data, other.data + (width * height * channels), data);
    }
    else
    {
        data = nullptr;
    }
}

// Copy assignment operator
Image &Image::operator=(const Image &other)
{
    if (this != &other)
    {            // Check for self-assignment
        clear(); // Free existing resources

        width = other.width;
        height = other.height;
        channels = other.channels;

        if (other.data)
        {
            data = new float[width * height * channels];
            std::copy(other.data, other.data + (width * height * channels), data);
        }
        else
        {
            data = nullptr;
        }
    }
    return *this;
}

// Move constructor
Image::Image(Image &&other) noexcept
    : data(other.data), width(other.width), height(other.height), channels(other.channels)
{
    other.data = nullptr; // Leave the moved-from object in a valid state
    other.width = other.height = other.channels = 0;
}

// Move assignment operator
Image &Image::operator=(Image &&other) noexcept
{
    if (this != &other)
    {            // Check for self-assignment
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
    return width;
}

int Image::getHeight() const
{
    return height;
}

int Image::getChannels() const
{
    return channels;
}

float *Image::getData() const
{
    return data;
}

ImageType Image::getType() const
{
    return imageType;
}

float *Image::operator()(int row, int col)
{
    // Check bounds
    if (row < 0 || row >= height || col < 0 || col >= width)
    {
        throw std::out_of_range("Index out of bounds");
    }
    // Calculate the index in the 1D vector
    int pointer = (row * width + col) * channels; // Adjust based on the number of channels
    return data + pointer; 
}
// Method to clear the image data
void Image::clear()
{
    if (data)
    {
        if (imageType == ImageType::TIFF)
        {
            delete[] data;
        }
        else
        {
            stbi_image_free(data);
        }
        data = nullptr;
    }
}

// Display image info
void Image::displayInfo() const
{
    std::cout << "Image Path: " << filePath << std::endl;
    std::cout << "Width: " << width << "px" << std::endl;
    std::cout << "Height: " << height << "px" << std::endl;
    std::cout << "Channels: " << channels << std::endl;
    std::cout << "Image Type: " << toString(imageType) << std::endl;
}
