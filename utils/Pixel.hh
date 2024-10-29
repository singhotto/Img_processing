#ifndef PIXEL__HH
#define PIXEL__HH

class Pixel
{
private:
    float *r;
    float *g;
    float *b;
    float *a;
    int channels;
public:
    Pixel(float *v);
    Pixel(float *r, float *g, float *b);
    Pixel(float *r, float *g, float *b, float *a);

    // Copy constructor
    Pixel(const Pixel &other);

    // Move constructor
    Pixel(Pixel &&other) noexcept;

    Pixel &operator=(const Pixel &other);

    Pixel &operator=(Pixel &&other) noexcept;

    void setValue(const float value);
    void setAlpha(const float a);
    void setRGB(const float r, const float g, const float b);
    void setRGB(const float r, const float g, const float b, const float a);
    void setAll(const float value);
    void set(const Pixel& pixel);
    void swap(Pixel& other);
    void add(const float c);

    float getR() const;
    float getG() const;
    float getB() const;
    float getA() const;
};

#endif