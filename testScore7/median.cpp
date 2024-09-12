#include <vector>
#include <algorithm>
#include "median.h"

double median(const std::vector<double>& vec)
{
    double median;
    
    std::vector<double> vec2 = vec;
    std::sort(vec2.begin(), vec2.end());

    const std::vector<double>::size_type mid = vec2.size() / 2;

    if (vec2.size() % 2 != 0) {
        median = vec2[mid];
    }
    else {
        median = (vec2[mid] + vec2[mid - 1]) / 2;
    }

    return median;
}