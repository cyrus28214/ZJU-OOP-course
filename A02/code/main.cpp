#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <vector>

#include "Database.h"

using namespace std;

int main() {
    string line;

    Database db;
    Summary summary;

    while (getline(cin, line)) { // read input line by line
        if (line.empty()) {
            break;
        }
        string student, course;
        double score;
        istringstream iss(line);
        iss >> student >> course >> score; // parse input
        db.set_score(student, course, score); // set score in database
    }

    auto students = db.get_students(); // get students from database
    auto courses = db.get_courses(); // get courses from database

    // set table width
    const int col_w = 10;

    // print table header
    cout << left << setw(col_w) << "no"
        << setw(col_w) << "name";

    for (const auto& course : courses) {
        cout << setw(col_w) << course;
    }
    cout << setw(col_w) << "average" << endl;

    // print table body
    for (size_t i = 0; i < students.size(); ++i) {
        string& student = students[i];
        size_t no = i + 1;

        cout << left << setw(col_w) << no
            << setw(col_w) << student;

        for (const auto& course : courses) {
            optional<double> score = db.get_score(students[i], course);
            if (score.has_value()) {
                cout << setw(col_w) << score.value();
            }
            else {
                cout << setw(col_w) << ""; // no score
            }
        }
        summary = Summary(db.get_records_by_student(student));
        cout << setw(col_w) << summary.get_avg() << endl;
    }

    // print table footer
    vector<Summary> summaries;
    for (const auto& course : courses) {
        summaries.push_back(Summary(db.get_records_by_course(course)));
    }

    // print average, min, max
    cout << left << setw(col_w) << "" << setw(col_w) << "average";
    for (const auto& summary : summaries) {
        cout << setw(col_w) << summary.get_avg();
    }
    cout << endl;

    // print min
    cout << left << setw(col_w) << "" << setw(col_w) << "min";
    for (const auto& summary : summaries) {
        cout << setw(col_w) << summary.get_min();
    }
    cout << endl;

    // print max
    cout << left << setw(col_w) << "" << setw(col_w) << "max";
    for (const auto& summary : summaries) {
        cout << setw(col_w) << summary.get_max();
    }
    cout << endl;

    return 0;
}
