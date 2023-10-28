#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

// https://acm.timus.ru/problem.aspx?space=1&num=1656

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;


void print_results(vvi& results) {
    for (auto& row : results) {
        for (auto& el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

struct point {
    int x;
    int y;
};

void visit_neighbour(int n, point current_point, int dx, int dy, vvb& visited, std::list<point>& queue) {
    point new_point{.x = current_point.x + dx, .y = current_point.y + dy};
    if ((new_point.x < 0) || (new_point.x >= n) || (new_point.y < 0) || (new_point.y >=n)) {
        return;
    }
    if (visited[new_point.x][new_point.y]) {
        return;
    }
    visited[new_point.x][new_point.y] = true;
    queue.push_back(new_point);
}


int main() {
    int n;
    vi height;
    std::cin >> n;
    for (int i = 0; i < n * n; ++i) {
        int x;
        std::cin >> x;
        height.push_back(x);
    }
    sort(height.begin(), height.end(), std::greater<>{});

    vvi results;
    vvb visited;
    for (size_t i = 0; i < n; ++i) {
        results.emplace_back(n, 0);
        visited.emplace_back(n, false);
    }
    std::list<point> queue;

    point start_point = {.x = n / 2, .y = n / 2};
    queue.push_back(start_point);
    visited[start_point.x][start_point.y] = true;

    int index = 0;
    while (!queue.empty()) {
        point current_point = queue.front();
        queue.pop_front();
        results[current_point.x][current_point.y] = height[index];
        ++index;
        visit_neighbour(n, current_point, +1, 0, visited, queue);
        visit_neighbour(n, current_point, -1, 0, visited, queue);
        visit_neighbour(n, current_point, 0, +1, visited, queue);
        visit_neighbour(n, current_point, 0, -1, visited, queue);
    }
    print_results(results);
}
