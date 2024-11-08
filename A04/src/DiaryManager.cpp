#include "DiaryManager.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

/**
 * @brief Construct a new Diary Manager:: Diary Manager object
 * @param path the path to the directory where the diary entries are stored
 */
DiaryManager::DiaryManager(const fs::path& path) {
    this->path = path;
    this->init_diary_index(); // initialize diary index
}

/**
 * @brief Initialize the diary index by reading the names of the files in the directory
 */
void DiaryManager::init_diary_index() {
    ensure_directory_exists(this->path); // ensure the directory exists
    try {
        for (const auto& entry : fs::directory_iterator(this->path)) { // iterate over all files in the directory
            if (entry.is_regular_file() && entry.path().extension() == ".txt") { // check if the file is a regular file and has a .txt extension
                std::string file_name = entry.path().stem().string(); // get the file name without the extension
                std::istringstream iss(file_name); // create a string stream from the file name
                std::optional<std::time_t> date = read_time(iss, "%Y-%m-%d"); // try to parse the file name as a date
                if (!date) { // if the file name is not in the format YYYY-MM-DD, ignore it
                    std::cerr << "WARN: name of file \"" << file_name << "\" is not in the format YYYY-MM-DD, ignored" << std::endl;
                    continue;
                }
                diary_index.insert(*date); // insert the date into the diary index
            }
        }
    }
    catch (const fs::filesystem_error& e) { // if an error occurs while reading the directory, print an error message and exit
        std::cerr << "ERROR: failed to initialize diary index: " << e.what() << std::endl;
        exit(-1);
    }
    catch (...) { // if an unknown error occurs, print an error message and exit
        std::cerr << "ERROR: failed to initialize diary index: unknown error" << std::endl;
        exit(-1);
    }
}

/**
 * @brief Add or replace a diary entry
 * @param entry the diary entry to add or replace
 *
 * If the diary entry already exists, it will be replaced with the new entry. The entry will be stored in a file named YYYY-MM-DD.txt in the directory specified by the path member variable.
 */
void DiaryManager::add_or_replace_entry(const DiaryEntry& entry) {
    std::ostringstream oss;
    write_time(oss, entry.timestamp, "%Y-%m-%d"); // write the timestamp to a string stream in the format YYYY-MM-DD
    std::string file_name = oss.str();
    fs::path file_path = this->path / (file_name + ".txt"); // create the file path by appending .txt to the file name
    try {
        std::ofstream file(file_path);
        if (!file.is_open()) { // if the file cannot be opened for writing, print an error message and exit
            std::cerr << "ERROR: failed to open file \"" << file_path << "\" for writing" << std::endl;
            exit(-1);
        }
        file << entry.content; // write the content of the diary entry to the file
    }
    catch (const fs::filesystem_error& e) { // if an error occurs while writing to the file, print an error message and exit
        std::cerr << "ERROR: failed to write diary content to file \"" << file_path << "\" : " << e.what() << std::endl;
        exit(-1);
    }
    catch (...) { // if an unknown error occurs, print an error message and exit
        std::cerr << "ERROR: failed to write diary content to file \"" << file_path << "\" : unknown error" << std::endl;
        exit(-1);
    }
    this->diary_index.insert(entry.timestamp); // insert the timestamp into the diary index
}

/**
 * @brief Read a diary entry from a file
 * @param timestamp the timestamp of the diary entry to read
 */
DiaryEntry DiaryManager::read_entry(std::time_t timestamp) const {
    std::ostringstream oss;
    write_time(oss, timestamp, "%Y-%m-%d"); // write the timestamp to a string stream in the format YYYY-MM-DD
    std::string time_str = oss.str();
    fs::path file_path = this->path / (time_str + ".txt"); // create the file path by appending .txt to the file name
    try {
        std::ifstream file(file_path);
        if (!file.is_open()) { // if the file cannot be opened for reading, print an error message and exit
            std::cerr << "ERROR: failed to open file \"" << file_path << "\" for reading" << std::endl;
            exit(-1);
        }
        std::stringstream buffer;
        buffer << file.rdbuf(); // read the content of the file into a string stream
        std::string content = buffer.str();
        return DiaryEntry{ timestamp, content }; // return a DiaryEntry object with the timestamp and content
    }
    catch (const fs::filesystem_error& e) { // if an error occurs while reading the directory, print an error message and exit
        std::cerr << "ERROR: failed to read diary content from file \"" << file_path << "\" : " << e.what() << std::endl;
        exit(-1);
    }
    catch (...) { // if an unknown error occurs, print an error message and exit
        std::cerr << "ERROR: failed to read diary content from file \"" << file_path << "\" : unknown error" << std::endl;
        exit(-1);
    }
}

/**
 * @brief Print a diary entry to an output stream
 * @param os the output stream to print to
 * @param entry the diary entry to print
 */
void DiaryManager::print_diary_entry(std::ostream& os, std::time_t target) const {
    DiaryEntry entry = this->read_entry(target); // read the diary entry from the file
    DiaryManager::print_entry(os, entry); // print the diary entry to the output stream
}

/**
 * @brief Print all diary entries in a given range to an output stream
 * @param os the output stream to print to
 * @param start the start of the range (inclusive)
 * @param end the end of the range (inclusive)
 * @param verbose whether to print the full diary entry or just the date and title
 */
void DiaryManager::print_diary_range(std::ostream& os, std::time_t start, std::time_t end, bool verbose) const {
    auto it_lower = this->diary_index.lower_bound(start); // find the first diary entry with a timestamp greater than or equal to start
    auto it_upper = this->diary_index.upper_bound(end); // find the first diary entry with a timestamp greater than end
    for (auto it = it_lower; it != it_upper; ++it) { // iterate over the diary entries in the range [start, end]
        if (verbose) this->print_diary_entry(os, *it);
        else {
            DiaryEntry entry = this->read_entry(*it);
            write_time(os, entry.timestamp, "%Y-%m-%d");
            os << std::endl;
        }
    }
}

/**
 * @brief Print all diary entries to an output stream
 * @param os the output stream to print to
 * @param verbose whether to print the full diary entry or just the date and title
 */
void DiaryManager::print_diary_all(std::ostream& os, bool verbose) const {
    for (auto it = this->diary_index.begin(); it != this->diary_index.end(); ++it) {
        if (verbose) this->print_diary_entry(os, *it);
        else {
            DiaryEntry entry = this->read_entry(*it);
            write_time(os, entry.timestamp, "%Y-%m-%d");
            os << std::endl;
        }
    }
}

/**
 * @brief Print a diary entry to an output stream
 * @param os the output stream to print to
 * @param entry the diary entry to print
 */
void DiaryManager::print_entry(std::ostream& os, const DiaryEntry& entry) {
    os << "\t\033[32m[ "; // ANSI green color
    write_time(os, entry.timestamp, "%Y-%m-%d"); // write the timestamp to the output stream in the format YYYY-MM-DD
    os << " ]\033[0m" << std::endl; // ANSI reset color
    os << entry.content << std::endl; // write the content of the diary entry to the output stream
}

/**
 * @brief Remove a diary entry from the diary
 * @param target the timestamp of the diary entry to remove
 */
void DiaryManager::remove_entry(std::time_t target) {
    std::ostringstream oss;
    write_time(oss, target, "%Y-%m-%d"); // write the timestamp to a string stream in the format YYYY-MM-DD
    std::string time_str = oss.str();
    fs::path file_path = this->path / (time_str + ".txt"); // construct the file path from the timestamp
    try {
        if (!fs::remove(file_path)) { // remove the file from the filesystem
            std::cerr << "ERROR: failed to remove file \"" << file_path << "\"" << std::endl;
            exit(-1);
        }
    }
    catch (const fs::filesystem_error& e) { // if an error occurs, print an error message and exit
        std::cerr << "ERROR: failed to remove file \"" << file_path << "\" : " << e.what() << std::endl;
        exit(-1);
    }
    catch (...) { // if an unknown error occurs, print an error message and exit
        std::cerr << "ERROR: failed to remove file \"" << file_path << "\" : unknown error" << std::endl;
        exit(-1);
    }
    this->diary_index.erase(target); // remove the timestamp from the diary index
}

/**
 * @brief Check if a diary entry exists for a given timestamp
 * @param time the timestamp to check
 * @return true if the diary entry exists, false otherwise
 */
bool DiaryManager::has_entry(std::time_t time) const {
    return this->diary_index.find(time) != this->diary_index.end();
}