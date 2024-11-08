#include "DiaryManager.h"
#include "utils.h"
#include <sstream>
#include <cstring>

/**
 * @file pdlist.cpp
 * @brief List diary entities
 */

namespace fs = std::filesystem;

const char* help = "Usage: pdlist [<begin> <end>] [-v|--verbose]\n"
" - print diary entries in the range [<begin>, <end>] if provided <begin> and <end>\n"
" - print all diary entries if not\n"
" - dates are in YYYY-MM-DD format\n"
" - add -v or --verbose to print full diary content\n";


int main(int argc, char* argv[]) {
    bool verbose = false;
    int ss_cnt = 0;
    std::stringstream ss[2];
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) { // if verbose flag is set
            verbose = true;
        }
        else if (ss_cnt < 2) {
            ss[ss_cnt++] << argv[i];
        }
        else { // invalid usage
            std::cerr << help << std::endl;
            return -1;
        }
    }
    DiaryManager dm(fs::current_path() / DEFAULT_DIARY_STORAGE_DIR); // create a diary manager
    if (ss_cnt == 2) { // if the usage is valid, print diary entities in the range [<begin>, <end>]
        std::optional<std::time_t> begin = read_time(ss[0], "%Y-%m-%d"); // parse begin date
        std::optional<std::time_t> end = read_time(ss[1], "%Y-%m-%d"); // parse end date
        if (!begin || !end) { // if the parsing failed, print help message
            std::cerr << help << std::endl;
            return -1;
        }
        dm.print_diary_range(std::cout, begin.value(), end.value(), verbose); // print diary entities in the range [<begin>, <end>]
        return 0;
    }
    if (ss_cnt == 0) {
        dm.print_diary_all(std::cout, verbose);
        return 0;
    }
    // invalid usage
    std::cerr << help << std::endl;
    return -1;
}