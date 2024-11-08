#include "Database.h"

/**
 * @brief create a new student if not exists
 * @param student the student name
 * @return true if the student is created
 */
bool Database::create_student_if(const std::string& student) {
    if (student_index.find(student) == student_index.end()) { // not exists
        students.push_back(student);
        return true;
    }
    return false;
}

/**
 * @brief create a new course if not exists
 * @param course the course name
 * @return true if the course is created
 */
bool Database::create_course_if(const std::string& course) {
    if (course_index.find(course) == course_index.end()) {  // not exists
        courses.push_back(course);
        return true;
    }
    return false;
}

/**
 * @brief get the score of a student in a course
 * @param student the student name
 * @param course the course name
 * @return the score if exists, otherwise std::nullopt
 */
std::optional<double> Database::get_score(
    const std::string& student,
    const std::string& course
) const {
    auto it = student_course_index.find({ student, course });
    if (it == student_course_index.end()) {
        return std::nullopt;
    }
    return records.at(it->second).score;
}

/**
 * @brief set the score of a student in a course
 * @param student the student name
 * @param course the course name
 * @param score the score
 */
void Database::set_score(
    const std::string& student,
    const std::string& course,
    const double score
) {
    std::optional<double> old_score = get_score(student, course);
    id_t record_id;
    if (old_score) { // exists
        record_id = student_course_index.at({ student, course });
        records.at(record_id).score = score;
    }
    else { // not exists
        create_student_if(student); // create if not exists
        create_course_if(course); // create if not exists
        record_id = records.size();
        records.push_back(Record{ student, course, score }); // create a new record
        student_index.insert({ student, record_id }); // insert to index
        course_index.insert({ course, record_id }); // insert to index
        student_course_index.insert({ {student, course}, record_id }); // insert to index
    }
}

/**
 * @brief get all students
 * @return all students
 */
std::vector<std::string> Database::get_students() const {
    return students;
}

/**
 * @brief get all courses
 * @return all courses
 */
std::vector<std::string> Database::get_courses() const {
    return courses;
}

/**
 * @brief get all records of a student
 * @param student the student name
 */
std::vector<Record> Database::get_records_by_student(
    const std::string& student
) const {
    std::vector<Record> result;
    auto range = student_index.equal_range(student); // get all records of the student
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(records.at(it->second));
    }
    return result;
}

/**
 * @brief get all records of a course
 * @param course the course name
 */
std::vector<Record> Database::get_records_by_course(
    const std::string& course
) const {
    std::vector<Record> result;
    auto range = course_index.equal_range(course); // get all records of the course
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(records.at(it->second));
    }
    return result;
}