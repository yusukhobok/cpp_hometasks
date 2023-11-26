#ifndef HOMETASK_5_EDITOR_FEATURE_H
#define HOMETASK_5_EDITOR_FEATURE_H

#include <string>

enum class Color{ Red, Green, Blue};

class Feature {
private:
    Color color;
protected:
    [[nodiscard]] std::string color_to_string() const;
public:
    explicit Feature(Color color);
    [[nodiscard]] virtual std::string get_paint_data() const = 0;
    virtual ~Feature() = default;
};


#endif //HOMETASK_5_EDITOR_FEATURE_H
