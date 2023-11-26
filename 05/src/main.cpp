#include <memory>


#include "circle.h"
#include "rectangle.h"
#include "feature.h"
#include "model.h"
#include "view.h"
#include "controller.h"


int main() {
    Model model;
    View view(model);
    Controller controller(view, model);

    auto circle = std::static_pointer_cast<Feature>(std::make_shared<Circle>(1, 2, 3.5, Color::Red));
    auto rectangle = std::static_pointer_cast<Feature>(std::make_shared<Rectangle>(1, 1, 2, 3, Color::Blue));

    controller.load_from_file("example");
    controller.add_feature(circle);
    controller.add_feature(rectangle);
    controller.delete_feature(circle);
    controller.save_to_file("example");
}
