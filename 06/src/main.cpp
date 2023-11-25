#include <list>
#include <vector>
#include "matrix.hpp"


int main() {
    Matrix<int, 0> matrix;

    const int length = 10;
    int reversed_i;
    for (auto i = 0; i < length; ++i) {
        reversed_i = length - i - 1;
        matrix[i][i] = i;
        matrix[i][reversed_i] = reversed_i;
    }

    for (auto i = 1; i < length - 1; ++i) {
        for (auto j = 1; j < length - 1; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << matrix.size() << std::endl << std::endl;

    for (auto cell : matrix) {
        auto [x, y] = cell.first;
        auto value = cell.second;
        std::cout << "(" << x << ", " << y << ") = " << value << std::endl;
    }

    return 0;
}
