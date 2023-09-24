#include <iostream>
#include <string>
#include <vector>

// https://acm.timus.ru/problem.aspx?space=1&num=1197

std::pair<int, int> parse(std::string field) {
    int row = field[1] - '0';
    int column = field[0] - 'a' + 1;
    return std::make_pair(row, column);
}

bool check_coordinates(int x, int y) {
    return (x >= 1) && (x <= 8) && (y >= 1) && (y <= 8);
}

int calc_moves_count(std::pair<int, int> coordinates) {
    int count = 0;
    std::vector<std::pair<int, int>> variants = {
            std::make_pair(1, 2),
            std::make_pair(1, -2),
            std::make_pair(-1, 2),
            std::make_pair(-1, -2),
            std::make_pair(2, 1),
            std::make_pair(-2, 1),
            std::make_pair(2, -1),
            std::make_pair(-2, -1),
    };
    for (const auto& variant : variants) {
        int x = coordinates.first + variant.first;
        int y = coordinates.second + variant.second;
        if (check_coordinates(x, y)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n;
    std::string field;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> field;
        std::pair<int, int> coordinates = parse(field);
        std::cout << calc_moves_count(coordinates) << std::endl;
    }
}
