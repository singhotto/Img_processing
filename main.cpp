#include <iostream>
#include <string>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"
#include "utils/ImageProcessor.hh"

int main(){
    const std::string fileName = "ultrasound-fetus2.tiff";
    // const std::string fileName = "big_color.png";
    ImageHandler& handler = ImageHandler::getInstance();
    ImageProcessor& processor = ImageProcessor::getInstance();

    //original Image
    Image img = handler.loadImage("../images/" + fileName);

    //image to work
    // processor.generateHistogram(img);
    // Image newImage = processor.toBinary(img);
    // Image newImage = processor.changeBrightness(img, -100);
    // Image newImage = processor.rgb2Grayscale(img);
    
    Image newImage = processor.negativeImage(img);

    // Image newImage = processor.rotateDown(img);

    // processor.generateHistogram(img);
    // Image newImage = processor.histEqualization(img);
    // processor.generateHistogram(newImage);

    
    //Saving Image
    handler.saveImage("../output/" + fileName, newImage);

    return 0;
}