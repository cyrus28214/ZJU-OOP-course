#include "DiaryManager.h"
#include "utils.h"
#include <sstream>

/**
 * @file pdshow.cpp
 * @brief Print the content of the entity of the date
 */

namespace fs = std::filesystem;

const char* help = "Usage: pdshow [<date: YYYY-MM-DD> [<date> [...]]]\n - print the content of the entity of the date(s)";
int main(int argc, char* argv[]) {
    if (argc < 2) { /// if the usage is invalid, print help message
        std::cerr << help << std::endl;
        return -1;
    }
    DiaryManager dm(fs::current_path() / DEFAULT_DIARY_STORAGE_DIR); // initialize DiaryManager
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        std::optional<std::time_t> date = read_time(ss, "%Y-%m-%d"); // read the date
        if (!date) {
            std::cerr << "WARN: failed to parsing date: " << argv[i] << ", ignored." << std::endl;
            continue;
        }
        if (!dm.has_entry(*date)) {
            std::cerr << "WARN: no such diary for date: " << argv[i] << ", ignored." << std::endl;
            continue;
        }
        dm.print_diary_entry(std::cout, *date); // print the content of the entity of the date
        return 0;
    }
    return 0;
}