#include <Direction.h>

// the directions
const char* DIRECTION_NAMES[(size_t)Direction::MAX_NUM] = {
    "nil",
    "west",
    "east",
    "south",
    "north",
    "down",
    "up"
};

/**
 * @brief Parse a direction from a string
 * @param str the string to parse
 * @return the parsed direction
 */
Direction parse_direction(const char* str) {
    for (size_t i = 0; i < (size_t)Direction::MAX_NUM; ++i) {
        if (strcmp(str, DIRECTION_NAMES[i]) == 0) {
            return (Direction)i;
        }
    }
    return Direction::NIL;
}

/**
 * @brief Stringify a direction
 * @param dir the direction to stringify
 * @return the stringified direction
 */
const char* stringify_direction(Direction dir) {
    return DIRECTION_NAMES[(size_t)dir];
}