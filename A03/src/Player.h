#ifndef PLAYER_H
#define PLAYER_H

#include "Direction.h"

/**
 * @brief Class representing the player in the game.
 */
class Player {
public:
    Player() : x(0), y(0), z(0) {};
    Player(int x, int y, int z) : x(x), y(y), z(z) {};
    void move(Direction direction);
    void get_pos(int& x, int& y, int& z) const;
    void set_pos(int x, int y, int z);
    int gold = 0;
    int health = 100;
    int attack = 5;
    int defense = 5;
private:
    int x, y, z;
};

#endif // !PLAYER_H