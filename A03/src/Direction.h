#ifndef DIRECTION_H
#define DIRECTION_H

#include <cstddef>
#include <cstring>

enum class Direction {
    NIL,
    WEST,
    EAST,
    SOUTH,
    NORTH,
    DOWN,
    UP,
    MAX_NUM
};

extern const char* DIRECTION_NAMES[(size_t)Direction::MAX_NUM];

Direction parse_direction(const char* str);
const char* stringify_direction(Direction dir);

#endif // !DIRECTION_