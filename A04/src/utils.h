#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <iostream>
#include <optional>
#include <filesystem>

extern const char* DEFAULT_DIARY_STORAGE_DIR; ///< The default directory for storing diaries.

/**
 * @brief Read a time from an input stream.
 * @param is The input stream.
 * @param format The format string.
 * @return std::optional<std::time_t> The time, or std::nullopt if the time could not be read.
 */
std::optional<std::time_t> read_time(std::istream& is, const char* format);

/**
 * @brief Write a time to an output stream.
 * @param os The output stream.
 * @param t The time.
 * @param format The format string.
 */
void write_time(std::ostream& os, std::time_t t, const char* format);

/**
 * @brief Ensure that a directory exists.
 * @param path The path to the directory.
 */
void ensure_directory_exists(const std::filesystem::path& path);


#endif // !UTILS_H