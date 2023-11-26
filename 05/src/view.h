#ifndef HOMETASK_5_EDITOR_VIEW_H
#define HOMETASK_5_EDITOR_VIEW_H

#include <string>

#include "model.h"


class View {
private:
    const Model& model;

public:
    View(const Model& a_model);
    void render();
};


#endif //HOMETASK_5_EDITOR_VIEW_H
