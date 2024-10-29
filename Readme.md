# ImageProcessor

The `ImageProcessor` class is a powerful utility for performing various image processing tasks. This singleton class provides methods to manipulate and enhance images, including color conversions, brightness adjustments, histogram equalization, filtering, and more.

## Features

- **Color Conversion**
  - Convert images to grayscale
  - Convert images to RGB
  - Convert images to RGBA

- **Thresholding**
  - Convert images to binary using a threshold

- **Intensity and Brightness Adjustments**
  - Set intensity levels for images
  - Change brightness based on a threshold

- **Image Manipulations**
  - Rotate images left, right, or down
  - Mirror images along the X or Y axis
  - Crop images to a specified size and position
  - Overlay one image on another

- **Image Effects**
  - Generate negative images
  - Add salt-and-pepper noise to images

- **Filtering**
  - Apply median filtering to reduce noise
  - Apply Gaussian smoothing for blurring effects

- **Histogram Generation**
  - Generate and save histograms for image analysis

## Usage

To use the `ImageProcessor`, simply include the header file and call the methods as needed. Here's an example of how to get started:

```cpp
#include "ImageProcessor.h"

int main() {
    ImageProcessor& processor = ImageProcessor::getInstance();
    
    Image img; // Load or create an image
    processor.conv2Grayscale(img); // Convert to grayscale
    processor.changeBrightness(img, 50); // Change brightness

    // More processing...
    
    processor.generateHistogram(img); // Generate and save histogram

    return 0;
}

## Installation

To get started with the `ImageProcessor`, clone this repository to your local machine using the following command:

```bash
git clone https://github.com/yourusername/ImageProcessor.git

### Requirements

- C++11 or later
- A compatible image handling library (ensure that the `Image` class implementation supports the required image formats)

### Building the Project

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/yourusername/ImageProcessor.git

2. Navigate to the cloned directory:

   ```bash
   cd ImageProcessor

3. Compile the project using your preferred build system. If you are using g++, you can compile with the following command:

   ```bash
   g++ -o image_processor main.cpp ImageProcessor.cpp

