#include "DiaryManager.h"
#include "utils.h"
#include <iostream>
#include <sstream>

/**
 * @file pdadd.cpp
 * @brief Add or replace a diary entry
 */

namespace fs = std::filesystem;

const char* help = "Usage: pdadd <date: YYYY-MM-DD>\n"
" - then you will be able to input the content of the diary, end with a single line of \".\", or EOF";

int main(int argc, char* argv[]) {
    if (argc != 2) { // if the uesage is wrong
        std::cerr << help << std::endl;
        return -1;
    }
    DiaryManager dm(fs::current_path() / DEFAULT_DIARY_STORAGE_DIR); // create a diary manager
    std::stringstream ss(argv[1]);
    std::optional<std::time_t> date = read_time(ss, "%Y-%m-%d"); // read time_t from format string
    if (!date) { // if the date is invalid
        std::cerr << help << std::endl;
        return -1;
    }
    std::cout << "Enter the content of the diary (end with a single line of \".\" or EOF): " << std::endl; // prompt user to input the content
    std::string content, line;
    while (std::getline(std::cin, line) && line != ".") { // read line by line until the user input "."
        content += line + "\n";
    }
    dm.add_or_replace_entry(DiaryEntry{ *date, content }); // add or replace the entry
    return 0;
}