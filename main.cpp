#include <iostream>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"

int main(){
    Image img = ImageHandler::getInstance().loadImage("../images/2nd-from-top-USA.tiff");
    // int size = img.getHeight() * img.getWidth() * img.getChannels();
    // for(int i = 0; i<size/4; i++){
    //     float& data = img.getData()[i];
    //     if(data > 0){
    //         std::cout<<(int)data<<"\n";

    //     }
    // }
    // Image newImg("tt.jpg", newData, img.getWidth(), img.getHeight(), img.getChannels(), ImageType::JPEG);
    ImageHandler::getInstance().saveImage("../output/a.tiff", img);

    return 0;
}