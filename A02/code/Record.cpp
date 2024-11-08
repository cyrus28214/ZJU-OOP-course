#include <algorithm>

#include "Record.h"

/**
 * @brief Construct a new Summary:: Summary object
 * @param records
 */
Summary::Summary(const std::vector<Record>& records) {
    count = 0;
    sum = 0;
    max = 0;
    min = 0;
    if (records.empty()) return;
    for (const auto& record : records) { // for each record in records
        count++; // increment count
        if (count == 1 || record.score > max) max = record.score; // update max
        if (count == 1 || record.score < min) min = record.score; // update min
        sum += record.score; // update sum
    }
}

/**
 * @return the average score
 */
double Summary::get_avg() const {
    return sum / count;
}

/**
 * @return the max score
 */
double Summary::get_max() const {
    return max;
}

/**
 * @return the min score
 */
double Summary::get_min() const {
    return min;
}