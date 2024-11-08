#include "student.h"

double Student::get_average() {
    double sum = 0;
    for (int i = 0; i < NUM_SCORES; i++) {
        sum += scores[i];
    }
    return sum / NUM_SCORES;
}

std::istream& operator>>(std::istream& in, Student& s) {
    in >> s.name;
    for (int i = 0; i < Student::NUM_SCORES; i++) {
        in >> s.scores[i];
    }
    return in;
}