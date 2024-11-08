#include "summary.h"
#include <limits>
#include <algorithm>

Summary::Summary() {
    this->count = 0;
    for (int i = 0; i < Summary::NUM_COLS; ++i) {
        this->average[i] = 0;
        this->min[i] = std::numeric_limits<int>::max();
        this->max[i] = std::numeric_limits<int>::min();
    }
}

void Summary::add(int* row) {
    this->count++;
    for (int i = 0; i < Summary::NUM_COLS; ++i) {
        this->average[i] += row[i];
        this->min[i] = std::min(this->min[i], row[i]);
        this->max[i] = std::max(this->max[i], row[i]);
    }
}

void Summary::finalize() {
    if (this->count > 0) {
        for (int i = 0; i < Summary::NUM_COLS; ++i) {
            this->average[i] /= this->count;
        }
    }
}