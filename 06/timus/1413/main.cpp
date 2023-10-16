#include <iostream>
#include <unordered_map>
#include <cmath>
#include <iomanip>

// https://acm.timus.ru/problem.aspx?space=1&num=1413


int main() {
    char c;
    std::unordered_map<char, int> count;

    while (std::cin.get(c))
    {
        if (c == '0') {
            break;
        }
        if (c == '5') {
            continue;
        }
        if (c >= '1' and c <= '9') {
            (count[c])++;
        }
    }

    double x = count['6'] - count['4'] + (count['3'] + count['9'] - count['1'] - count['7']) * sqrt(2)/2;
    double y = count['8'] - count['2'] + (count['7'] + count['9'] - count['1'] - count['3']) * sqrt(2)/2;

    std::cout << std::fixed << std::setprecision(12) << x << " " << y;
}
