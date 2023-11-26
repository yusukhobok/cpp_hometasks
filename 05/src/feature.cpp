#include <stdexcept>
#include "feature.h"

Feature::Feature(Color color): color(color) {}

std::string Feature::color_to_string() const {
    switch (color) {
        case Color::Red:
            return "red";
        case Color::Green:
            return "green";
        case Color::Blue:
            return "blue";
        default:
            throw std::runtime_error("");
    }
}
