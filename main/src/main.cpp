#include <vector>
#include <iostream>
#include "stats.hpp"

int main() {
    std::vector<int> v{7, 5, 16, 9};

    int avg = mean(v.data(), v.size());
    std::cout << "mean = " << avg << std::endl;
    return EXIT_SUCCESS;
}