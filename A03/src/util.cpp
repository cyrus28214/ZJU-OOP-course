#include "util.h"

/**
 * @brief Split a string by spaces into a vector of strings
 *
 * Any continuous spaces are treated as a single space
 */
std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> result;
    std::string current;
    for (char c : s) {
        if (c == ' ') {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        }
        else {
            current += c;
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}

/**
 * @brief Trim leading and trailing spaces from a string
 * @param s The string to trim
 * @return The trimmed string
 */
std::string trim(const std::string& s) {
    // Find the position of the first non-space character
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start])) {
        ++start;
    }

    // Find the position of the last non-space character
    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1])) {
        --end;
    }

    // Return the substring without leading and trailing spaces
    return s.substr(start, end - start);
}