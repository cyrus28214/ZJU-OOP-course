#include "Castle.h"

/**
 * @brief Check if the given coordinates are within the bounds of the castle
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @return true if the coordinates are within the bounds, false otherwise
 */
bool Castle::check_bounds(int x, int y, int z) {
    return x >= x_min && x <= x_max && y >= y_min && y <= y_max && z >= z_min && z <= z_max;
}

/**
 * @brief Constructor for the Castle class
 * @param x_min minimum x-coordinate
 * @param x_max maximum x-coordinate
 * @param y_min minimum y-coordinate
 * @param y_max maximum y-coordinate
 * @param z_min minimum z-coordinate
 * @param z_max maximum z-coordinate
 */
Castle::Castle(int x_min, int x_max, int y_min, int y_max, int z_min, int z_max) :
    x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max), z_min(z_min), z_max(z_max)
{
    int x_size = x_max - x_min + 1;
    int y_size = y_max - y_min + 1;
    int z_size = z_max - z_min + 1;
    // resize the rooms vector to the correct size
    rooms.resize(x_size, std::vector<std::vector<RoomPtr>>(y_size, std::vector<RoomPtr>(z_size, nullptr)));
}

/**
 * @brief Get the room at the given coordinates
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @return RoomPtr to the room at the given coordinates
 * @throws "Room out of bounds" if the coordinates are out of bounds
 */
Castle::RoomPtr Castle::get_room(int x, int y, int z) {
    if (!this->check_bounds(x, y, z)) {
        throw "Room out of bounds";
    }
    return rooms[x - x_min][y - y_min][z - z_min];
}

/**
 * @brief Place a room at the given coordinates
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @param room RoomPtr to the room to place
 * @return RoomPtr to the room that was placed
 */
Castle::RoomPtr Castle::place_room(int x, int y, int z, RoomPtr room) {
    if (!this->check_bounds(x, y, z)) {
        throw "Room out of bounds";
    }
    return rooms[x - x_min][y - y_min][z - z_min] = room;
}

/**
 * @brief Get the exits from the room at the given coordinates
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate
 * @return vector of Direction enums representing the exits from the room
 */
std::vector<Direction> Castle::get_exits(int x, int y, int z) {
    std::vector<Direction> neighbors;
    if (x > x_min && this->get_room(x - 1, y, z) != nullptr) {
        neighbors.push_back(Direction::WEST);
    }
    if (x < x_max && this->get_room(x + 1, y, z) != nullptr) {
        neighbors.push_back(Direction::EAST);
    }
    if (y > y_min && this->get_room(x, y - 1, z) != nullptr) {
        neighbors.push_back(Direction::SOUTH);
    }
    if (y < y_max && this->get_room(x, y + 1, z) != nullptr) {
        neighbors.push_back(Direction::NORTH);
    }
    if (z > z_min && this->get_room(x, y, z - 1) != nullptr) {
        neighbors.push_back(Direction::DOWN);
    }
    if (z < z_max && this->get_room(x, y, z + 1) != nullptr) {
        neighbors.push_back(Direction::UP);
    }
    return neighbors;
}