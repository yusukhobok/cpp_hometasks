#include <iostream>
#include <vector>
#include <algorithm>

// https://acm.timus.ru/problem.aspx?space=1&num=2115

std::vector<int> get_data() {
    std::vector<int> students;
    int n, student;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> student;
        students.push_back(student);
    }
    return students;
}

void print_vector(const std::vector<int> &vec) {
    for (const auto &el: vec) {
        std::cout << el << " ";
    }
}

std::vector<int>
find_difference_indexes(const std::vector<int> &original_vector, const std::vector<int> &sorted_vector) {
    std::vector<int> difference_indexes;
    for (int i = 0; i < original_vector.size(); ++i) {
        if (original_vector[i] != sorted_vector[i]) {
            difference_indexes.push_back(i + 1);
        }
    }
    return difference_indexes;
}

int main() {
    std::vector<int> students = get_data();
    bool is_ascending_sorted = std::is_sorted(students.begin(), students.end());
    bool is_descending_sorted = std::is_sorted(students.begin(), students.end(), std::greater<>{});
    if (is_ascending_sorted || is_descending_sorted) {
        std::cout << "Nothing to do here";
    } else {
        std::vector<int> ascending_sorted_students = students;
        std::vector<int> descending_sorted_students = students;
        std::sort(ascending_sorted_students.begin(), ascending_sorted_students.end());
        std::sort(descending_sorted_students.begin(), descending_sorted_students.end(), std::greater<>{});
        std::vector<int> difference_indexes_ascending = find_difference_indexes(students, ascending_sorted_students);
        std::vector<int> difference_indexes_descending = find_difference_indexes(students, descending_sorted_students);
        std::vector<int> difference_indexes = difference_indexes_ascending.size() < difference_indexes_descending.size()
                                              ? difference_indexes_ascending : difference_indexes_descending;
        if (difference_indexes.size() > 2) {
            std::cout << "No hope";
        } else {
            std::cout << "Yes" << std::endl;
            print_vector(difference_indexes);
        }
    }
}
