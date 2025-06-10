#include "color.h"
#include <iostream>
#include <tuple>

int main() {
    Color primaryRed("red");
    Color primaryBlue(0, 0, 255);
    Color semiTransparentGreen(0, 255, 0, 128);
    Color undefinedColor("unknown");

    std::cout << "Red component: " << primaryRed.getRedComponent() << std::endl;
    std::cout << "Green transparency: " << semiTransparentGreen.getAlphaComponent() << std::endl;

    primaryBlue.setGreenComponent(150);
    std::cout << "Modified blue: " << primaryBlue.toRGBString() << std::endl;

    std::cout << "Red (RGB): " << primaryRed.toRGBString() << std::endl;
    std::cout << "Blue (RGBA): " << primaryBlue.toRGBAString() << std::endl;
    std::cout << "Green (HEX): " << semiTransparentGreen.toHexString() << std::endl;

    Color blendedPurple = primaryRed.blendWith(primaryBlue);
    std::cout << "Blended purple: " << blendedPurple.toRGBString() << std::endl;

    auto [redValue, greenValue, blueValue] = blendedPurple.getRGBValues();
    std::cout << "Purple RGB components: " << redValue << " " << greenValue << " " << blueValue << std::endl;

    auto [r, g, b, a] = semiTransparentGreen.getRGBAValues();
    std::cout << "Green RGBA components: " << r << " " << g << " " << b << " " << a << std::endl;

    std::cout << "Undefined color: " << undefinedColor << std::endl;

    return 0;
}