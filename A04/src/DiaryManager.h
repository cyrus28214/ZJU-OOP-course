#ifndef DIARY_MANAGER_H
#define DIARY_MANAGER_H

#include "DiaryEntry.h"
#include <filesystem>
#include <ctime>
#include <set>

/**
 * @class DiaryManager
 * @brief Manages diary entries stored in a directory
 */
class DiaryManager {
public:
    /**
     * @brief Construct a new Diary Manager:: Diary Manager object
     * @param path the path to the directory where the diary entries are stored
     */
    DiaryManager(const std::filesystem::path& path);

    /**
     * @brief Add or replace a diary entry
     * @param entry the diary entry to add or replace
     *
     * If the diary entry already exists, it will be replaced with the new entry. The entry will be stored in a file named YYYY-MM-DD.txt in the directory specified by the path member variable.
     */
    void add_or_replace_entry(const DiaryEntry& entry);

    /**
     * @brief Print a diary entry to an output stream
     * @param os the output stream to print to
     * @param entry the diary entry to print
     */
    void print_diary_entry(std::ostream& os, std::time_t target) const;

    /**
     * @brief Print all diary entries in a given range to an output stream
     * @param os the output stream to print to
     * @param start the start of the range (inclusive)
     * @param end the end of the range (inclusive)
     * @param verbose whether to print the full diary entry or just the date
     */
    void print_diary_range(std::ostream& os, std::time_t start, std::time_t end, bool verbose = false) const;

    /**
     * @brief Print all diary entries to an output stream
     * @param os the output stream to print to
     * @param verbose whether to print the full diary entry or just the date and title
     */
    void print_diary_all(std::ostream& os, bool verbose = false) const;

    /**
     * @brief Print a diary entry to an output stream
     * @param os the output stream to print to
     * @param entry the diary entry to print
     */
    void remove_entry(std::time_t target);

    /**
     * @brief Check if a diary entry exists for a given timestamp
     * @param time the timestamp to check
     * @return true if the diary entry exists, false otherwise
     */
    bool has_entry(std::time_t time) const;

private:
    std::filesystem::path path;
    std::set<std::time_t> diary_index;

    /**
     * @brief Initialize the diary index by reading the names of the files in the directory
     */
    void init_diary_index();

    /**
     * @brief Read a diary entry from a file
     * @param timestamp the timestamp of the diary entry to read
     */
    DiaryEntry read_entry(std::time_t time) const;

    /**
     * @brief Print a diary entry to an output stream
     * @param os the output stream to print to
     * @param entry the diary entry to print
     */
    static void print_entry(std::ostream& os, const DiaryEntry& entry);
};

#endif // !DIARY_MANAGER_H