#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
public:
    static const int NUM_SCORES = 3;

    std::string name;
    int scores[NUM_SCORES];
    double get_average();
    friend std::istream& operator>>(std::istream& in, Student& s);
};

#endif // STUDENT_H