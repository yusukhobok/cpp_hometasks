#include <string>
#include "rectangle.h"

Rectangle::Rectangle(double x_min, double x_max, double y_min, double y_max, Color color) :
        Feature(color), x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max) {}

std::string Rectangle::get_paint_data() const {
    return "circle: xmin = " + std::to_string(x_min) + ", xmax = " + std::to_string(x_max)
           + ", ymin = " + std::to_string(y_min) + ", ymax = " + std::to_string(y_max) +
           ", color = " + color_to_string() + "\n";
}