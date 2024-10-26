#include <iostream>
#include <string>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"
#include "utils/ImageProcessor.hh"

int main(){
    const std::string fileName = "cameraman.jpg";
    // const std::string fileName = "big_color.png";
    ImageHandler& handler = ImageHandler::getInstance();
    ImageProcessor& processor = ImageProcessor::getInstance();

    //original Image
    Image img = handler.loadImage("../images/" + fileName);

    //image to work
    // processor.rgb2Grayscale(img);
    // processor.toBinary(img);
    // processor.changeBrightness(img, -100);

    // processor.histEqualization(img);

    // processor.rotateLeft(img);
    // processor.rotateRight(img);
    // processor.rotateDown(img);

    // processor.mirrorX(img);
    // processor.mirrorY(img);
    
    // processor.negativeImage(img);

    // processor.generateHistogram(img);
    // processor.generateHistogram(img);
    // processor.generateHistogram(newImage);

    
    //Saving Image
    handler.saveImage("../output/" + fileName, img);

    return 0;
}