#include "Player.h"

/**
 * @brief move player in the given direction
 * @param direction
 */
void Player::move(Direction direction) {
    switch (direction) {
    case Direction::NORTH:
        y++; break;
    case Direction::SOUTH:
        y--; break;
    case Direction::EAST:
        x++; break;
    case Direction::WEST:
        x--; break;
    case Direction::UP:
        z++; break;
    case Direction::DOWN:
        z--; break;
    }
}

/**
 * @brief get player position
 * @param[out] x
 * @param[out] y
 * @param[out] z
 */
void Player::get_pos(int& x, int& y, int& z) const {
    x = this->x;
    y = this->y;
    z = this->z;
}


/**
 * @brief set player position
 * @param x
 * @param y
 * @param z
 */
void Player::set_pos(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}