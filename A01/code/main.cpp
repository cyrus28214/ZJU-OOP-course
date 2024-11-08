#include <iostream>
#include <climits>
#include <algorithm>

#include "student.h"
#include "summary.h"

/*
example ouput:
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
*/

void printStatistics(Student students[]) {
    // Print the header
    std::cout << "no\tname\tscore1\tscore2\tscore3\taverage" << std::endl;

    Summary summary;

    // The body of the table
    for (int i = 0; i < 10; ++i) {
        int no = i + 1;
        std::cout << no << "\t"
            << students[i].name << "\t"
            << students[i].scores[0] << "\t"
            << students[i].scores[1] << "\t"
            << students[i].scores[2] << "\t"
            << students[i].get_average() << std::endl;
        summary.add(students[i].scores);
    }

    summary.finalize();

    // The footer of the table
    std::cout << "\taverage";
    for (int i = 0; i < 3; ++i)
        std::cout << "\t" << summary.average[i];
    std::cout << std::endl;

    std::cout << "\tmin";
    for (int i = 0; i < 3; ++i)
        std::cout << "\t" << summary.min[i];
    std::cout << std::endl;

    std::cout << "\tmax";
    for (int i = 0; i < 3; ++i)
        std::cout << "\t" << summary.max[i];
    std::cout << std::endl;
}

int main() {
    Student students[10];
    for (int i = 0; i < 10; ++i) {
        std::cin >> students[i];
    }
    printStatistics(students);
    return 0;
}

