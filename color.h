#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <tuple>
#include <iostream>

class Color {
private:
    int redComponent;
    int greenComponent;
    int blueComponent;
    int alphaComponent;

public:
    Color(int red, int green, int blue);
    Color(int red, int green, int blue, int alpha);
    Color(const std::string& colorName);

    int getRedComponent() const;
    int getGreenComponent() const;
    int getBlueComponent() const;
    int getAlphaComponent() const;

    void setRedComponent(int red);
    void setGreenComponent(int green);
    void setBlueComponent(int blue);
    void setAlphaComponent(int alpha);

    std::string toRGBString() const;
    std::string toRGBAString() const;
    std::string toHexString() const;

    std::tuple<int, int, int> getRGBValues() const;
    std::tuple<int, int, int, int> getRGBAValues() const;

    Color blendWith(const Color& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Color& color);
};

#endif