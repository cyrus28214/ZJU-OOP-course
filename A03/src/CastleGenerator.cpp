#include <queue>
#include <array>
#include <vector>
#include <algorithm>
#include <random>
#include "CastleGenerator.h"

/**
 * @brief Generates a random castle
 * @param seed The seed for the random number generator
 * @return A pointer to the generated castle
 */
Castle* CastleGenerator::generate(unsigned int seed) {
    Castle* castle = new Castle(-2, 2, -2, 2, 0, 2);
    std::vector<Castle::RoomPtr> rooms{
        std::make_shared<LobbyRoom>("Lobby"), // fixed
        std::make_shared<AbandonedArmoryRoom>("Armory Room 1"), // random ordered
        std::make_shared<AbandonedArmoryRoom>("Armory Room 2"), // random ordered
        std::make_shared<GrandHallRoom>("Grand Hall 1"), // random ordered
        std::make_shared<GrandHallRoom>("Grand Hall 2"), // random ordered
        std::make_shared<CreepyLibraryRoom>("Creepy Library 1"), // random ordered
        std::make_shared<CreepyLibraryRoom>("Creepy Library 2"), // random ordered
        std::make_shared<SecretPassageRoom>("Secret Passage 1"), // random ordered
        std::make_shared<SecretPassageRoom>("Secret Passage 2"), // random ordered
        std::make_shared<DungeonCellRoom>("Dungeon Cell 1"),// random ordered
        std::make_shared<DungeonCellRoom>("Dungeon Cell 2"),// random ordered
        std::make_shared<PrincessRoom>("Prison Cell (Princess)"), // random ordered
        std::make_shared<MonsterRoom>("Monster Room") // random ordered
    };
    std::default_random_engine engine(seed); // random engine
    std::shuffle(rooms.begin() + 1, rooms.end() - 2, engine); // random shuffle
    std::vector<std::array<int, 3>> positions{ // the positions
        {0, 0, 0},
        {-1, 0, 0},
        {-1, 1, 0},
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 0},
        {-1, 0, 1},
        {-1, 1, 1},
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {-1, 0, 2},
        {-1, 1, 2}
    };

    for (int i = 0; i < rooms.size(); ++i) {
        std::array<int, 3> pos = positions[i];
        castle->place_room(pos[0], pos[1], pos[2], rooms[i]);
    }
    return castle;
}

/**
 *    ^
 *    N
 *    |
 * <-W+E->
 *    |
 *    S
 *    v
 *
 * 1F:
 *  __ __ __
 * |__|__|__|
 * |__|__|__|
 *     ^
 *     Lobby
 *
 * 2F:
 *  __ __ __
 * |__|__|__|
 * |__|  |__|
 *
 * 3F:
 *  __
 * |__|
 * |__|
 */