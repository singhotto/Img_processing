#include "Pixel.hh"

Pixel::Pixel(float *r) : r(nullptr), g(nullptr), b(nullptr), a(nullptr), channels(1)
{
    this->r = r;
}

Pixel::Pixel(float *r, float *g, float *b) : a(nullptr), channels(3)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Pixel::Pixel(float *r, float *g, float *b, float *a) : channels(4)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Pixel::Pixel(const Pixel &other) : r(other.r),
                                   g(other.g),
                                   b(other.b),
                                   a(other.a),
                                   channels(other.channels)
{
}

Pixel::Pixel(Pixel &&other) noexcept : r(other.r), g(other.g), b(other.b), a(other.a), channels(other.channels)
{
    other.r = nullptr;
    other.g = nullptr;
    other.b = nullptr;
    other.a = nullptr;
}

Pixel &Pixel::operator=(const Pixel &other)
{
    if (this == &other)
        return *this;

    // Copy the data
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
    this->a = other.a;
    channels = other.channels;

    return *this;
}

Pixel &Pixel::operator=(Pixel &&other) noexcept
{
    if (this == &other)
        return *this; // Self-assignment check
    // Move the resources
    r = other.r;
    g = other.g;
    b = other.b;
    a = other.a;
    channels = other.channels;

    // Nullify the source pointers
    other.r = nullptr;
    other.g = nullptr;
    other.b = nullptr;
    other.a = nullptr;

    return *this;
}

void Pixel::setValue(const float value)
{
    *this->r = value;
}

void Pixel::setAlpha(const float a)
{
    *this->a = a;
}

void Pixel::setRGB(const float r, const float g, const float b)
{
    *this->r = r;
    *this->g = g;
    *this->b = b;
}

void Pixel::setRGB(const float r, const float g, const float b, const float a)
{
    *this->r = r;
    *this->g = g;
    *this->b = b;
    *this->a = a;
}

void Pixel::setAll(const float value)
{
    *this->r = value;
    *this->g = value;
    *this->b = value;
}

void Pixel::set(const Pixel &pixel)
{
    if(channels == 1){
        setValue(pixel.getR());
        return;
    }

    if (channels == 3){
        setRGB(pixel.getR(), pixel.getG(), pixel.getB());
        return;
    }

    if(channels == 4){
        setRGB(pixel.getR(), pixel.getG(), pixel.getB(), pixel.getA());
    }
}

void Pixel::swap(Pixel &other)
{
    if(channels == 1){
        float v = other.getR();
        other.setValue(*this->r);
        setValue(v);
        return;
    }

    if (channels == 3){
        float otr = other.getR();
        float og = other.getG();
        float ob = other.getB();

        other.setRGB(*r, *g, *b);
        setRGB(otr, og, ob);

        return;
    }

    if(channels == 4){
        float otr = other.getR();
        float og = other.getG();
        float ob = other.getB();
        float oa = other.getA();

        other.setRGB(*r, *g, *b, *a);
        setRGB(otr, og, ob, oa);
    }
}

void Pixel::add(const float c)
{
    if(channels == 1){
        setValue(*r + c);
        return;
    }

    if (channels == 3){
        setRGB(*r + c, *g + c, *b + c);
        return;
    }

    if(channels == 4){
        setRGB(*r + c, *g + c, *b + c, *a);
    }
}

float Pixel::getR() const
{
    return *r;
}

float Pixel::getG() const
{
    return *g;
}

float Pixel::getB() const
{
    return *b;
}

float Pixel::getA() const
{
    return *a;
}