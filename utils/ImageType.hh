// ImageType.h
#ifndef IMAGETYPE_H
#define IMAGETYPE_H

enum class ImageType {
    JPEG,
    JPG,
    PNG,
    GIF,
    BMP,
    TIFF,
    WEBP,
    TGA,
    UNKNOWN
};

// Optional: Function to convert enum to string for display purposes
inline const char* toString(ImageType type) {
    switch (type) {
        case ImageType::JPEG: return "JPEG";
        case ImageType::PNG: return "PNG";
        case ImageType::GIF: return "GIF";
        case ImageType::BMP: return "BMP";
        case ImageType::TIFF: return "TIFF";
        case ImageType::WEBP: return "WEBP";
        case ImageType::TGA: return "TGA";
        default: return "Unknown";
    }
}

#endif // IMAGETYPE_H
