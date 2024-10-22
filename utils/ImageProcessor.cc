#include "ImageProcessor.hh"

ImageProcessor::ImageProcessor(){}

ImageProcessor &ImageProcessor::getInstance()
{
    static ImageProcessor instance; // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

Image ImageProcessor::rgb2Color(const Image &image)
{
    int size = image.getWidth() * image.getHeight();
    float * data = new float[size * image.getChannels()];
    float* pointer = image.getData();

    int channels = image.getChannels();
    int alpha = image.getData()[4];

    std::cout<<"Image color channels: "<<image.getChannels()<<"\n";

    for (int i = 0; i<size; i++){
        int idx1 = i * channels;
        int idx2 = i * channels + 1;
        int idx3 = i * channels + 2;
        float temp = pointer[idx1] * 0.3f + pointer[idx2] * 0.59f + pointer[idx3] * 0.11f;
        data[idx1] = temp;
        data[idx2] = temp;
        data[idx3] = temp;
        if(channels == 4){
            data[i*channels +3] = alpha;
        }
    }

    return Image("temp", data, image.getWidth(), image.getHeight(), image.getChannels(), image.getType(),image.getBPC());
}
