#ifndef CASTLE_H
#define CASTLE_H

#include <vector>
#include <memory>
#include "Room.h"
#include "Direction.h"

/**
 * @brief Class representing a castle
 */
class Castle {
public:
    Castle(int x_min, int x_max, int y_min, int y_max, int z_min, int z_max);
    using RoomPtr = std::shared_ptr<Room>;
    bool check_bounds(int x, int y, int z);
    RoomPtr get_room(int x, int y, int z);
    RoomPtr place_room(int x, int y, int z, RoomPtr room);
    std::vector<Direction> get_exits(int x, int y, int z);
private:
    std::vector < std::vector<std::vector<RoomPtr>>> rooms;
    int x_min, x_max, y_min, y_max, z_min, z_max;
};


#endif // !CASTLE_H