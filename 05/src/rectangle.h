#ifndef HOMETASK_5_EDITOR_RECTANGLE_H
#define HOMETASK_5_EDITOR_RECTANGLE_H


#include "feature.h"

class Rectangle final : public Feature {
private:
    double x_min;
    double x_max;
    double y_min;
    double y_max;
public:
    Rectangle(double x_min, double x_max, double y_min, double y_max, Color color);
    [[nodiscard]] std::string get_paint_data() const override;
};


#endif //HOMETASK_5_EDITOR_RECTANGLE_H
