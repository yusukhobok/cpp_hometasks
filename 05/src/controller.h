#ifndef HOMETASK_5_EDITOR_CONTROLLER_H
#define HOMETASK_5_EDITOR_CONTROLLER_H

#include "view.h"
#include "model.h"

class Controller {
private:
    View& view;
    Model& model;

public:
    Controller(View& a_view, Model& a_model);
    void load_from_file(const std::string& path);
    void save_to_file(const std::string& path);
    void add_feature(std::shared_ptr<Feature>& feature);
    void delete_feature(std::shared_ptr<Feature>& feature);
};


#endif //HOMETASK_5_EDITOR_CONTROLLER_H
