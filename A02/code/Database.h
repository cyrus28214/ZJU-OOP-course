#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <vector>
#include <optional>
#include <cstdint>

#include "Record.h"

using id_t = uint32_t;

class Database {
public:
    /**
     * @brief create a new student if not exists
     * @param student the student name
     * @return true if the student is created
     */
    bool create_student_if(const std::string& student); // create student if not exists, return true if created

    /**
     * @brief create a new course if not exists
     * @param course the course name
     * @return true if the course is created
     */
    bool create_course_if(const std::string& course); // create course if not exists, return true if created

    /**
     * @brief get the score of a student in a course
     * @param student the student name
     * @param course the course name
     * @return the score if exists, otherwise std::nullopt
     */
    std::optional<double> get_score(
        const std::string& student,
        const std::string& course
    ) const;

    /**
     * @brief set the score of a student in a course
     * @param student the student name
     * @param course the course name
     * @param score the score
     */
    void set_score(
        const std::string& student,
        const std::string& course,
        const double score
    ); // set score, create student and course if not exists

    /**
     * @brief get all students
     * @return all students
     */
    std::vector<std::string> get_students() const;

    /**
     * @brief get all courses
     * @return all courses
     */
    std::vector<std::string> get_courses() const;


    /**
     * @brief get all records of a student
     * @param student the student name
     */
    std::vector<Record> get_records_by_student(
        const std::string& student
    ) const;


    /**
     * @brief get all records of a course
     * @param course the course name
     */
    std::vector<Record> get_records_by_course(
        const std::string& course
    ) const;
private:
    std::vector<Record> records;
    std::vector<std::string> students, courses;
    std::multimap<std::string, id_t> student_index, course_index;
    std::map<std::pair<std::string, std::string>, id_t> student_course_index; // composite index
};

#endif // DATABASE_H