#include "Aurora/Renderer/Color.h"

namespace Aurora
{

    const Color Color::White = Color(255, 255, 255);
    const Color Color::Black = Color(0, 0, 0);
    const Color Color::Red = Color(255, 0, 0);
    const Color Color::Green = Color(0, 255, 0);
    const Color Color::Blue = Color(0, 0, 255);
    const Color Color::Yellow = Color(255, 255, 0);
    const Color Color::Cyan = Color(0, 255, 255);
    const Color Color::Magenta = Color(255, 0, 255);

    static constexpr Color FromRGB(
        uint8_t r,
        uint8_t g,
        uint8_t b)
    {
        return Color(r, g, b, 255);
    }

    static constexpr Color FromRGBA(
        uint8_t r,
        uint8_t g,
        uint8_t b,
        uint8_t a)
    {
        return Color(r, g, b, a);
    }

}