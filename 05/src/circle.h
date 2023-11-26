#ifndef HOMETASK_5_EDITOR_CIRCLE_H
#define HOMETASK_5_EDITOR_CIRCLE_H

#include "feature.h"

class Circle final : public Feature {
private:
    double x;
    double y;
    double radius;
public:
    Circle(double x, double y, double radius, Color color);
    [[nodiscard]] std::string get_paint_data() const override;
};


#endif //HOMETASK_5_EDITOR_CIRCLE_H
