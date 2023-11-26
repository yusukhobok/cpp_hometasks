#include <iostream>

#include "view.h"


View::View(const Model& a_model): model(a_model) {}

void View::render() {
    std::cout << model.get_paint_data() << std::endl;
}
