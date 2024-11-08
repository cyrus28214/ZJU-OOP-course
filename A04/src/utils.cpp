#include "utils.h"
#include <iomanip>
#include <filesystem>

namespace fs = std::filesystem;

const char* DEFAULT_DIARY_STORAGE_DIR = "pd"; ///< The default directory for storing diaries.

/**
 * @brief Read a time from an input stream.
 * @param is The input stream.
 * @param format The format string.
 * @return std::optional<std::time_t> The time, or std::nullopt if the time could not be read.
 */
std::optional<std::time_t> read_time(std::istream& is, const char* format) {
    std::tm tm{};
    is >> std::get_time(&tm, format); // read time
    if (is.fail()) { // check for failure
        return std::nullopt; // return std::nullopt if failed
    }
    return std::mktime(&tm); // return the time
}

/**
 * @brief Write a time to an output stream.
 * @param os The output stream.
 * @param t The time.
 * @param format The format string.
 */
void write_time(std::ostream& os, std::time_t t, const char* format) {
    os << std::put_time(std::localtime(&t), format); // write time
}

/**
 * @brief Ensure that a directory exists.
 * @param path The path to the directory.
 */
void ensure_directory_exists(const fs::path& path) {
    if (!fs::exists(path)) { // 
        std::cerr << "INFO: Can't find directory: " << path << ", creating it..." << std::endl;
        bool create_succ = false;
        try {
            create_succ = fs::create_directories(path); // create directory
        }
        catch (const fs::filesystem_error& e) { // catch exception
            std::cerr << "ERROR: Failed to create directory: " << path << ": " << e.what() << std::endl;
            exit(-1);
        }
        if (!create_succ) { // if failed to create directory
            std::cerr << "ERROR: Failed to create directory: " << path << std::endl;
            exit(-1);
        }
    }
}