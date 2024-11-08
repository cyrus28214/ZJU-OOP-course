#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <cstring>
#include "Direction.h"
#include "Player.h"

/**
 * @brief Abstract base class for all rooms
 */
class Room {
public:
    Room() : name(nullptr) {}
    Room(const char* name) : name(name) {}
    virtual const char* describe() const = 0;
    virtual ~Room() = default;
    const char* name;
};

class LobbyRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
};

class PrincessRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
    bool princess_in;
};

class MonsterRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
};

class AbandonedArmoryRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
    const char* name;
    const char* take(Player* player);
    bool empty = false;
};

class GrandHallRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
};

class CreepyLibraryRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
};

class SecretPassageRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
};

class DungeonCellRoom : public Room {
public:
    using Room::Room;
    const char* describe() const override;
};

#endif // !ROOM_H