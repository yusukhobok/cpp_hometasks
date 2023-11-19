#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <map>

using Point = std::pair<int, int>;

template <typename T, T default_value>
class Matrix {
private:
    std::map<Point, T> elements;

    class Row {
    private:
        Point coordinates;
        Matrix* matrix;
    public:
        Row(Matrix* matrix, int x) : matrix(matrix) {
            this->coordinates.first = x;
            this->coordinates.second = 0;
        }

        Row& operator[](int y) {
            coordinates.second = y;
            return *this;
        }

        Row& operator=(T value) {
            this->matrix->add(this->coordinates, value);
            return *this;
        }

        operator T() {
            return this->matrix->get(this->coordinates);
        }
    };

public:
    std::size_t size() {
        return this->elements.size();
    }

    auto begin() const {
        return std::begin(this->elements);
    }

    auto end() const {
        return std::end(this->elements);
    }

    Row operator[](int index) {
        Row row(this, index);
        return row;
    }

    void add(Point point, T value) {
        if (value != default_value) {
            this->elements[point] = value;
        } else if (this->elements.count(point) != 0) {
            elements.erase(point);
        }
    }

    T get(Point point) {
        if (this->elements.count(point) == 0) {
            return default_value;
        }
        return this->elements[point];
    }
};

#endif //MATRIX_HPP
