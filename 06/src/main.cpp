#include <list>
#include <string>
#include <vector>
#include <cassert>

#include "matrix.hpp"


int main() {
    Matrix<int, -1> matrix;
    assert(matrix.size() == 0);

    auto a = matrix[0][0];
    auto b = static_cast<int>(a);
    assert (b == -1);
    assert(matrix.size() == 0);

    matrix[100][100] = 314;
    assert (matrix[100][100] == 314);
    assert(matrix.size() == 1);

    for (auto c : matrix) {
        std::cout << c.first << c.second << c. << std::endl;
    }


    return 0;
}
