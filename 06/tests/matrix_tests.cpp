#include <gtest/gtest.h>
#include "../src/matrix.hpp"

TEST(
        MatrixTests,
        given_matrix__when_get_size__then_correct_size_returned
) {
    Matrix<int, 0> matrix;
    const int length = 10;
    int reversed_i;
    for (auto i = 0; i < length; ++i) {
        reversed_i = length - i - 1;
        matrix[i][i] = i;
        matrix[i][reversed_i] = reversed_i;
    }

    ASSERT_EQ(matrix.size(), 18);
}
