// color.cpp
#include "color.h"
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

static std::string convertToLowercase(const std::string& inputString) {
    std::string result = inputString;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return result;
}

static std::string convertToHex(int value) {
    std::stringstream stream;
    stream << std::hex << std::setw(2) << std::setfill('0') << value;
    return stream.str();
}

static const std::map<std::string, std::tuple<int, int, int>> COLOR_DATABASE = {
    {"black",   {0,   0,   0}},
    {"silver",  {192, 192, 192}},
    {"gray",    {128, 128, 128}},
    {"white",   {255, 255, 255}},
    {"maroon",  {128, 0,   0}},
    {"red",     {255, 0,   0}},
    {"purple",  {128, 0,   128}},
    {"fuchsia", {255, 0,   255}},
    {"green",   {0,   128, 0}},
    {"lime",    {0,   255, 0}},
    {"olive",   {128, 128, 0}},
    {"yellow",  {255, 255, 0}},
    {"navy",    {0,   0,   128}},
    {"blue",    {0,   0,   255}},
    {"teal",    {0,   128, 128}},
    {"aqua",    {0,   255, 255}}
};

Color::Color(int red, int green, int blue)
    : redComponent(0), greenComponent(0), blueComponent(0), alphaComponent(255) {
    setRedComponent(red);
    setGreenComponent(green);
    setBlueComponent(blue);
}

Color::Color(int red, int green, int blue, int alpha)
    : redComponent(0), greenComponent(0), blueComponent(0), alphaComponent(255) {
    setRedComponent(red);
    setGreenComponent(green);
    setBlueComponent(blue);
    setAlphaComponent(alpha);
}

Color::Color(const std::string& colorName)
    : redComponent(0), greenComponent(0), blueComponent(0), alphaComponent(255) {
    std::string lowercaseName = convertToLowercase(colorName);
    auto colorEntry = COLOR_DATABASE.find(lowercaseName);
    if (colorEntry != COLOR_DATABASE.end()) {
        auto [redValue, greenValue, blueValue] = colorEntry->second;
        setRedComponent(redValue);
        setGreenComponent(greenValue);
        setBlueComponent(blueValue);
    }
}

int Color::getRedComponent() const { return redComponent; }
int Color::getGreenComponent() const { return greenComponent; }
int Color::getBlueComponent() const { return blueComponent; }
int Color::getAlphaComponent() const { return alphaComponent; }

void Color::setRedComponent(int red) {
    redComponent = (red < 0) ? 0 : (red > 255) ? 255 : red;
}
void Color::setGreenComponent(int green) {
    greenComponent = (green < 0) ? 0 : (green > 255) ? 255 : green;
}
void Color::setBlueComponent(int blue) {
    blueComponent = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;
}
void Color::setAlphaComponent(int alpha) {
    alphaComponent = (alpha < 0) ? 0 : (alpha > 255) ? 255 : alpha;
}

std::string Color::toRGBString() const {
    return "rgb(" + std::to_string(redComponent) + ","
        + std::to_string(greenComponent) + ","
        + std::to_string(blueComponent) + ")";
}

std::string Color::toRGBAString() const {
    return "rgba(" + std::to_string(redComponent) + ","
        + std::to_string(greenComponent) + ","
        + std::to_string(blueComponent) + ","
        + std::to_string(alphaComponent) + ")";
}

std::string Color::toHexString() const {
    return "#" + convertToHex(redComponent)
        + convertToHex(greenComponent)
        + convertToHex(blueComponent)
        + (alphaComponent != 255 ? convertToHex(alphaComponent) : "");
}

std::tuple<int, int, int> Color::getRGBValues() const {
    return { redComponent, greenComponent, blueComponent };
}

std::tuple<int, int, int, int> Color::getRGBAValues() const {
    return { redComponent, greenComponent, blueComponent, alphaComponent };
}

Color Color::blendWith(const Color& other) const {
    return Color(
        (redComponent + other.redComponent) / 2,
        (greenComponent + other.greenComponent) / 2,
        (blueComponent + other.blueComponent) / 2,
        (alphaComponent + other.alphaComponent) / 2
    );
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << color.toRGBAString();
    return os;
}