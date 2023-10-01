#include "custom_vector.cpp"
#include "custom_allocator.cpp"
#include <iostream>
#include <map>

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    constexpr int count = 10;
    std::map<int, int> map_with_standard_allocator;
    for (int i = 0; i < count; ++i) {
        map_with_standard_allocator[i] = factorial(i);
    }

    std::map<int, int, std::less<>, CustomAllocator<std::pair<const int, int>, count>> map_with_custom_allocator;
    for (int i = 0; i < count; ++i) {
        map_with_custom_allocator[i] = factorial(i);
        std::cout << map_with_custom_allocator[i] << " ";
    }
    std::cout << std::endl;

    CustomVector<int> vector_with_standard_allocator;
    for (int i = 0; i < count; ++i) {
        vector_with_standard_allocator.push_back(i);
    }

    CustomVector<int, CustomAllocator<int, count>> vector_with_custom_allocator;
    for (int i = 0; i < count; ++i) {
        vector_with_custom_allocator.push_back(i);
    }

    for (int i = 0; i < count; ++i) {
        std::cout << vector_with_custom_allocator[i] << " ";
    }
}