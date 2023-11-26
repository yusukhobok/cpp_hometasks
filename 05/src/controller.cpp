#include "controller.h"


Controller::Controller(View& a_view, Model& a_model): view(a_view), model(a_model) {}

void Controller::load_from_file(const std::string& path) {
    model.load_from_file(path);
    view.render();
}

void Controller::save_to_file(const std::string& path) {
    model.save_to_file(path);
}

void Controller::add_feature(std::shared_ptr<Feature>& feature) {
    model.add_feature(feature);
    view.render();
}

void Controller::delete_feature(std::shared_ptr<Feature>& feature) {
    model.delete_feature(feature);
    view.render();
}
