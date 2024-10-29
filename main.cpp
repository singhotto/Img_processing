#include <iostream>
#include <string>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"
#include "utils/ImageProcessor.hh"

int main(){
    // const std::string fileName = "enea.png";
    // const std::string fileName = "zaffanella.png";
    // const std::string fileName = "2nd-from-top-USA.tiff";
    // const std::string fileName = "cameraman.jpg";
    // const std::string fileName = "40cm.tiff";
    // const std::string fileName = "bottels.png";
    // const std::string fileName = "cnls4.jpg";

    const std::string fileName = "bottels.png";
    const std::string fileName1 = "big_color.png";
    // const std::string fileName1 = "lena_noisy.png";

    ImageHandler& handler = ImageHandler::getInstance();
    ImageProcessor& processor = ImageProcessor::getInstance();

    //original Image
    Image img = handler.loadImage("../images/" + fileName);
    Image img1 = handler.loadImage("../images/" + fileName1);

    //temp
    processor.conv2rgba(img1);
    processor.setIntensity(img1, 150);
    
    // Image newImg = img;

    // processor.conv2Grayscale(img);
    // processor.conv2rgb(img);
    // processor.conv2rgba(img);
    // processor.toBinary(img);
    // processor.changeBrightness(img, 100);
    // processor.setIntensity(img, 150.0f);
    // processor.histEqualization(img);

    // processor.rotateLeft(img);
    // processor.rotateRight(img);
    // processor.rotateDown(img);

    // Image newImg = processor.cropImage(img, 50, 50, 50, 50);
    Image newImg = processor.overlayImage(img, img1, 50, 50);

    // processor.mirrorX(img);
    // processor.mirrorY(img);
    
    // processor.negativeImage(img);

    // processor.generateHistogram(img);

    // processor.medianFilter(img, 5);
    // processor.gaussianSmoothing(img, 3);
    
    // processor.addSaltPepper(img, 0.1f);

    img.displayInfo();
    newImg.displayInfo();

    //Saving Image
    handler.saveImage("../output/"+ newImg.getName(), newImg);
    handler.saveImage("../output/"+ img1.getName(), img1);

    //do what ever you want
    // for(int i = 0; i<img.getHeight(); i++){
    //     for(int j = 0; j<img.getWidth(); j++){
    //         Pixel p = img(i, j);
    //         if(p.getA() != 0 && p.getA() != 255)
    //             std::cout<<p.getA()<<"\n";
    //     }
    // }

    return 0;
}