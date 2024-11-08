#ifndef DIARY_ENTRY_H
#define DIARY_ENTRY_H

#include <string>
#include <ctime>

/**
 * @class DiaryEntry
 * @brief  A class representing a single diary entry.
 */
class DiaryEntry {
public:
    std::time_t timestamp;
    std::string content;
};

#endif // !DIARY_ENTRY_H