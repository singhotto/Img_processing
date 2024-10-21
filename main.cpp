#include <iostream>
#include "utils/Image.hh"
#include "utils/ImageHandler.hh"

int main(){
    Image img = ImageHandler::getInstance().loadImage("images/2nd-from-top-USA.tiff");

    ImageHandler::getInstance().saveImage("output/test.tiff", img);

    return 0;
}