#include <iostream>
#include <sstream>

#include "model.h"


void Model::clear() {
    features.clear();
}

void Model::load_from_file(const std::string &path) {
    std::cout << "load from file: " << path << std::endl;
}

void Model::save_to_file(const std::string &path) {
    std::cout << "save to file: " << path << std::endl;
}

void Model::add_feature(std::shared_ptr<Feature> &feature) {
    features.push_back(feature);
}

void Model::delete_feature(std::shared_ptr<Feature> &feature) {
    features.erase(
            std::remove(
                    features.begin(), features.end(), feature
            ),
            features.end()
    );
}

std::string Model::get_paint_data() const {
    std::ostringstream s;
    for (auto& feature : features) {
        s << feature->get_paint_data() << "; ";
    }
    return s.str();
}