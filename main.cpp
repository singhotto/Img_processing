#include <iostream>
#include <string>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"
#include "utils/ImageProcessor.hh"

int main(){
    const std::string fileName = "enea.png";
    // const std::string fileName = "zaffanella.png";
    // const std::string fileName = "2nd-from-top-USA.tiff";
    // const std::string fileName = "cameraman.jpg";
    // const std::string fileName = "lena_noisy.png";
    // const std::string fileName = "bottels.png";
    // const std::string fileName = "cnls4.jpg";

    ImageHandler& handler = ImageHandler::getInstance();
    ImageProcessor& processor = ImageProcessor::getInstance();

    //original Image
    Image img = handler.loadImage("../images/" + fileName);
    
    // Image newImg = img;

    // processor.rgb2Grayscale(img);
    // processor.grayscale2rgba(img);
    // processor.toBinary(img);
    // processor.changeBrightness(img, 100);
    // processor.setIntensity(img, 150.0f);
    // processor.histEqualization(img);

    // processor.rotateLeft(img);
    // processor.rotateRight(img);
    // processor.rotateDown(img);

    Image newImg = processor.cropImage(img, 50, 50, 50, 50);

    // processor.mirrorX(img);
    // processor.mirrorY(img);
    
    // processor.negativeImage(img);

    // processor.generateHistogram(img);

    // processor.medianFilter(img, 5);
    // processor.gaussianSmoothing(img, 3);
    
    // processor.addSaltPepper(img, 0.1f);

    newImg.displayInfo();
    //Saving Image
    handler.saveImage("../output/"+ newImg.getName(), newImg);
    // handler.saveImage("../output/"+ img.getName(), img);

    return 0;
}