#ifndef HOMETASK_5_EDITOR_MODEL_H
#define HOMETASK_5_EDITOR_MODEL_H

#include <vector>
#include <memory>
#include <string>

#include "feature.h"

class Model {
private:
    std::vector<std::shared_ptr<Feature>> features;
public:
    Model() = default;

    void clear();

    void load_from_file(const std::string& path);

    void save_to_file(const std::string& path);

    void add_feature(std::shared_ptr<Feature>& feature);

    void delete_feature(std::shared_ptr<Feature>& feature);

    std::string get_paint_data() const;
};


#endif //HOMETASK_5_EDITOR_MODEL_H
