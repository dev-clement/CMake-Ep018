#include "stats.hpp"
#include "supermath.hpp"

double mean(int *values, int count) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum  = add(sum, values[i]);
    }
    return static_cast<double>(sum / count);
}