#include "ImageHandler.hh"
#include <fstream>
#include <tiffio.h>

ImageType getImageType(const std::string &fileName)
{
    // Extract the extension by finding the last period
    std::string extension = fileName.substr(fileName.find_last_of(".") + 1);

    // Convert extension to lowercase for case-insensitive comparison
    for (auto &c : extension)
    {
        c = tolower(c);
    }

    // Match extension to ImageType
    if (extension == "jpg" || extension == "jpeg")
    {
        return ImageType::JPEG;
    }
    else if (extension == "png")
    {
        return ImageType::PNG;
    }
    else if (extension == "gif")
    {
        return ImageType::GIF;
    }
    else if (extension == "bmp")
    {
        return ImageType::BMP;
    }
    else if (extension == "tiff")
    {
        return ImageType::TIFF;
    }
    else if (extension == "webp")
    {
        return ImageType::WEBP;
    }
    else
    {
        return ImageType::UNKNOWN;
    }
}

unsigned char* loadTIFF(const char *filename, int &width, int &height, int &channels)
{
    TIFF *tiff = TIFFOpen(filename, "r");
    if (!tiff)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    // Get image dimensions
    TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &height);
    uint16 bitsPerSample;
    TIFFGetField(tiff, TIFFTAG_BITSPERSAMPLE, &bitsPerSample);
    uint16 samplesPerPixel;
    TIFFGetField(tiff, TIFFTAG_SAMPLESPERPIXEL, &samplesPerPixel);

    channels = samplesPerPixel;

    // Allocate memory for image data (width * height * channels)
    unsigned char * data = new unsigned char[width * height * channels];

    // Allocate memory for the scanline buffer
    tsize_t scanlineSize = TIFFScanlineSize(tiff);
    unsigned char *buffer = new unsigned char[scanlineSize];

    // Read scanline data
    for (int row = 0; row < height; row++)
    {
        if (TIFFReadScanline(tiff, buffer, row) < 0)
        {
            std::cerr << "Error reading scanline " << row << std::endl;
            TIFFClose(tiff);
            delete[] buffer;
            return nullptr;
        }

        // Copy data into the image buffer
        for (int col = 0; col < width; col++)
        {
            for (int ch = 0; ch < channels; ch++)
            {
                int idx = (row * width + col) * channels + ch;
                data[idx] = buffer[col * channels + ch]; // Now using unsigned char
            }
        }
    }

    // Clean up
    delete[] buffer;
    TIFFClose(tiff);
    
    return data;
}

bool saveTIFF(const char *filename, unsigned char* data, int width, int height, int channels)
{
    if (data == nullptr)
    {
        std::cerr << "No image data to save!" << std::endl;
        return false;
    }

    TIFF *tiff = TIFFOpen(filename, "w");
    if (!tiff)
    {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return false;
    }
    // Set TIFF fields
    TIFFSetField(tiff, TIFFTAG_IMAGEWIDTH, width);
    TIFFSetField(tiff, TIFFTAG_IMAGELENGTH, height);
    TIFFSetField(tiff, TIFFTAG_SAMPLESPERPIXEL, channels);
    TIFFSetField(tiff, TIFFTAG_BITSPERSAMPLE, channels); // Assume 8 bits per channel
    TIFFSetField(tiff, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(tiff, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);

    if (channels == 1)
    {
        TIFFSetField(tiff, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK); // Grayscale
    }
    else if (channels == 3)
    {
        TIFFSetField(tiff, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB); // RGB
    }

    // Write the image data row by row
    for (int row = 0; row < height; row++)
    {
        if (TIFFWriteScanline(tiff, data + row * width * channels, row) < 0)
        {
            std::cerr << "Error writing scanline " << row << std::endl;
            TIFFClose(tiff);
            return false;
        }
    }

    // Close the TIFF file
    TIFFClose(tiff);
    return true;
}

void copy2float(unsigned char *input, int input_size, float *output)
{
    for (int i = 0; i < input_size; i++)
        output[i] = (float)input[i];
}

void copy2char(float *input, size_t input_size, unsigned char *output)
{
    for (int i = 0; i < input_size; i++)
        output[i] = (unsigned char)input[i];
}

// Constructor definition
ImageHandler::ImageHandler() {}

// Static method to get the singleton instance
ImageHandler &ImageHandler::getInstance()
{
    static ImageHandler instance; // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

// Load an image from file into an Image object
Image ImageHandler::loadImage(const std::string &filename)
{
    int width;
    int height;
    int channels;
    ImageType type;
    unsigned char *data;
    std::ifstream file(filename.c_str());

    if (file.is_open())
    {
        file.close();
    }
    else
    {
        throw std::runtime_error("File does not exist.");
    }

    type = getImageType(filename);

    if (type == ImageType::UNKNOWN)
        throw std::runtime_error("Unsupported File!");

    if (type == ImageType::TIFF)
    {
        data = loadTIFF(filename.c_str(), width, height, channels);
    }
    else
    {
        data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    }

    int size = width * height * channels;
    float *fdata = new float[size];

    copy2float(data, size, fdata);
    delete[] data;

    return Image(filename, fdata, width, height, channels, type);
}

// Save the Image object to a file
void ImageHandler::saveImage(const std::string &filename, Image &image)
{
    if (image.getData() == nullptr)
    {
        throw std::runtime_error("No image data to save."); // Throw exception if no image data is present
    }

    image.displayInfo();

    ImageType type = image.getType();

    int size = image.getWidth() * image.getHeight() * image.getChannels();
    unsigned char *data = new unsigned char[size];

    copy2char(image.getData(), size, data);

    if (type == ImageType::PNG)
    {
        // Save as PNG
        if (!stbi_write_png(filename.c_str(), image.getWidth(), image.getHeight(), image.getChannels(), data, image.getWidth() * image.getChannels()))
        {
            throw std::runtime_error("Failed to save image as PNG: " + filename);
        }
    }
    else if (type == ImageType::JPEG)
    {
        // Save as JPEG
        if (!stbi_write_jpg(filename.c_str(), image.getWidth(), image.getHeight(), image.getChannels(), data, 100))
        {
            throw std::runtime_error("Failed to save image as JPEG: " + filename);
        }
    }
    else if (type == ImageType::BMP)
    {
        // Save as BMP
        if (!stbi_write_bmp(filename.c_str(), image.getWidth(), image.getHeight(), image.getChannels(), data))
        {
            throw std::runtime_error("Failed to save image as BMP: " + filename);
        }
    }
    else if (type == ImageType::TGA)
    {
        // Save as TGA
        if (!stbi_write_tga(filename.c_str(), image.getWidth(), image.getHeight(), image.getChannels(), data))
        {
            throw std::runtime_error("Failed to save image as TGA: " + filename);
        }
    }
    else if (type == ImageType::TIFF)
    {
        saveTIFF(filename.c_str(), data, image.getWidth(), image.getHeight(), image.getChannels());
    }
    else
    {
        throw std::runtime_error("Unsupported image type: " + filename);
    }
}
