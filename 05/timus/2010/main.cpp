#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// https://acm.timus.ru/problem.aspx?space=1&num=2010

bool first_row(int n, int x, int y) {
    return y == 1;
}

bool last_row(int n, int x, int y) {
    return y == n;
}

bool first_column(int n, int x, int y) {
    return x == 1;
}

bool last_column(int n, int x, int y) {
    return x == n;
}

bool check_coordinates(int n, int x, int y) {
    return (x >= 1) && (x <= n) && (y >= 1) && (y <= n);
}

int king_variants(int n, int x, int y) {
    if (n == 1) {
        return 0;
    }
    bool side_column = first_column(n, x, y) || last_column(n, x, y);
    bool side_row = first_row(n, x, y) || last_row(n, x, y);
    if (side_column && side_row) {
        return 3;
    }
    if (side_column || side_row) {
        return 5;
    }
    return 8;
}

int rook_variants(int n, int x, int y) {
    if (n == 1) {
        return 0;
    }
    return (n - 1) * 2;
}

int bishop_variants(int n, int x, int y) {
    if (n == 1) {
        return 0;
    }
    int dx_left = x - 1;
    int dx_right = n - x;
    int dy_bottom = y - 1;
    int dy_top = n - y;
    return std::min(dx_left, dy_bottom) + std::min(dx_left, dy_top) + std::min(dx_right, dy_top) +
           std::min(dx_right, dy_bottom);
}

int queen_variants(int n, int x, int y) {
    if (n == 1) {
        return 0;
    }
    return rook_variants(n, x, y) + bishop_variants(n, x, y);
}

int knight_variants(int n, int x, int y) {
    if (n == 1) {
        return 0;
    }
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
    for (const auto &variant: variants) {
        int new_x = x + variant.first;
        int new_y = y + variant.second;
        if (check_coordinates(n, new_x, new_y)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::cout << "King: " << king_variants(n, x, y) << std::endl;
    std::cout << "Knight: " << knight_variants(n, x, y) << std::endl;
    std::cout << "Bishop: " << bishop_variants(n, x, y) << std::endl;
    std::cout << "Rook: " << rook_variants(n, x, y) << std::endl;
    std::cout << "Queen: " << queen_variants(n, x, y) << std::endl;
}
