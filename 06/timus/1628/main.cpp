#include <iostream>
#include <vector>
#include <algorithm>

// https://acm.timus.ru/problem.aspx?space=1&num=1628

using vi = std::vector<int>;

struct Point {
    int x;
    int y;
};

//void update_points(std::vector<Point> &points, bool is_vertical, int number, int position) {
//    if (is_vertical) {
//        points.push_back(Point{number, position});
//    } else {
//        points.push_back(Point{position, number});
//    }
//}

int calc_for_line(vi positions, int size, std::vector<Point> &points, bool is_vertical, int number) {
    if (size == 1) {
        return 0;
    }
    if (positions.empty()) {
//        for (int j = 0; j < size; ++j) {
//            update_points(points, is_vertical, number, j);
//        }
        return 1;
    }
    positions.push_back(-1);
    positions.push_back(size);
    std::sort(positions.begin(), positions.end());
    int count = 0;
    int gap;
    for (int i = 0; i < positions.size() - 1; ++i) {
        gap = positions[i + 1] - positions[i] - 1;
        if (gap > 1) {
            ++count;
//            for (int j = positions[i] + 1; j < positions[i + 1]; ++j) {
//                update_points(points, is_vertical, number, j);
//            }
        }
        else if (gap == 1) {

        }
    }
    return count;
}

int main() {
    int m, n, k, x, y;
    std::cin >> m >> n >> k;

    std::vector<vi> data_for_columns(m);
    std::vector<vi> data_for_rows(n);
    std::vector<Point> points;
    for (int i = 0; i < k; ++i) {
        std::cin >> x >> y;
        data_for_columns[x - 1].push_back(y - 1);
        data_for_rows[y - 1].push_back(x - 1);
        points.push_back(Point{x - 1, y - 1});
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        count += calc_for_line(data_for_columns[i], n, points, true, i);
    }
    for (int i = 0; i < n; ++i) {
        count += calc_for_line(data_for_rows[i], m, points, false, i);
    }
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            Point current_point{i, j};
//            bool find = std::any_of(
//                    points.begin(),
//                    points.end(),
//                    [current_point](const Point &point) {
//                        return current_point.x == point.x && current_point.y == point.y;
//                    }
//            );
//            if (!find) {
//                ++count;
//            }
//        }
//    }

    std::cout << count;
}
