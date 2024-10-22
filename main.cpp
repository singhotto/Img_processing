#include <iostream>
#include <string>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"
#include "utils/ImageProcessor.hh"

int main(){
    const std::string fileName = "big_color.png";
    Image img = ImageHandler::getInstance().loadImage("../images/" + fileName);
    // int size = img.getHeight() * img.getWidth() * img.getChannels();
    // for(int i = 0; i<size/4; i++){
    //     float& data = img.getData()[i];
    //     if(data > 0){
    //         std::cout<<(int)data<<"\n";

    //     }
    // }
    Image newImage = ImageProcessor::getInstance().rgb2Color(img);
    // Image newImg("tt.jpg", newData, img.getWidth(), img.getHeight(), img.getChannels(), ImageType::JPEG);
    ImageHandler::getInstance().saveImage("../output/" + fileName, newImage);

    return 0;
}