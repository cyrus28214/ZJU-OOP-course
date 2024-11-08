#include "DiaryManager.h"
#include "utils.h"
#include <sstream>

/**
 * @file pdremove.cpp
 * @brief Remove the diary of the target day
 */

namespace fs = std::filesystem;

const char* help = "Usage: pdremove <date: YYYY-MM-DD>\n - remove the diary of the target day\n";

int main(int argc, char* argv[]) {
    if (argc != 2) { // if uesage is invalid, print help message
        std::cerr << help << std::endl;
        return -1;
    }
    DiaryManager dm(fs::current_path() / DEFAULT_DIARY_STORAGE_DIR); // create DiaryManager instance
    std::stringstream ss(argv[1]);
    std::optional<std::time_t> target = read_time(ss, "%Y-%m-%d"); // read target date
    if (!target) { // if parsing failed, print help message
        std::cerr << help << std::endl;
        return -1;
    }
    if (!dm.has_entry(*target)) { // if the target day has no diary, print error message
        std::cerr << "ERROR: cannot delete a diary that does not exist" << std::endl;
        return -1;
    }
    dm.remove_entry(*target); // remove diary of the target day
    return 0;
}