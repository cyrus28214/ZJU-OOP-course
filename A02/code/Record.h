#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <vector>

struct Record {
    std::string student, course;
    double score;
};

class Summary {
public:
    Summary() = default;

    /**
     * @brief Construct a new Summary:: Summary object
     * @param records
     */
    Summary(const std::vector<Record>& records);

    /**
     * @return the average score
     */
    double get_avg() const;

    /**
     * @return the max score
     */
    double get_max() const;

    /**
     * @return the min score
     */
    double get_min() const;
private:
    int count;
    double sum, max, min;
};

#endif // RECORD_H