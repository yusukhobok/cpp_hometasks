#include <string>
#include "circle.h"

Circle::Circle(double x, double y, double radius, Color color) : Feature(color), x(x), y(y), radius(radius) {}

std::string Circle::get_paint_data() const {
    return "circle: center = (" + std::to_string(x) + ", " + std::to_string(y) + "), radius = " +
           std::to_string(radius) + ", color = " + color_to_string() + "\n";
}