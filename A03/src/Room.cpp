#include "Room.h"

const char* LobbyRoom::describe() const {
    static const char* TEXT_LOBBY = "You are in the lobby of the castle. The walls are high, with faded tapestries hanging down, telling stories of battles long forgotten. A chandelier hangs crookedly from the ceiling, its crystals covered in dust. The air is still, but you can feel the weight of the castle's history around you.";
    return TEXT_LOBBY;
}

const char* PrincessRoom::describe() const {
    static const char* TEXT_PRINCESS_IN = "You step into a dimly lit chamber. At the far end, you see her - the princess!\nHer eyes light up with hope as she sees you. \"I knew someone would come for me,\" she whispers, her voice trembling with relief.\n\"We must leave before the monster finds us.\"\nShe takes your hand, and now, together, you must make it back to the castle's exit. But danger still lurks in the shadows...";
    static const char* TEXT_PRINCESS_NOT_IN = "You step back into the room where the princess was once trapped. The air is still cold, and the shadows still linger, but something feels different now. ";
    return princess_in ? TEXT_PRINCESS_IN : TEXT_PRINCESS_NOT_IN;
}

const char* MonsterRoom::describe() const {
    static const char* TEXT_MONSTER = "As you step into the room, a cold chill runs down your spine. The air grows heavy, and suddenly, from the shadows, the terrible monster appears! Its eyes glow with malice. You try to escape, but it's too late. The monster’s claws strike you down. Darkness surrounds you. The castle has claimed another victim.";
    return TEXT_MONSTER;
}

const char* AbandonedArmoryRoom::describe() const {
    static const char* TEXT_ARMORY = "You step into what appears to have once been an armory. Rusted swords and shattered shields are scattered across the floor, long forgotten by time. The air smells of metal and decay. In the dim light, a broken suit of armor lies slumped against the wall, a silent reminder of past battles.";
    static const char* TEXT_ARMORY_EMPTY = "You step into what appears to have once been an armory. The room is empty, the rusted swords and shattered shields have been taken.";
    return this->empty ? TEXT_ARMORY_EMPTY : TEXT_ARMORY;
}

/**
 * @brief take the sword and shield from armory
 * @param player
 * @return const char*
 */
const char* AbandonedArmoryRoom::take(Player* player) {
    if (this->empty) {
        return "The armory is already empty.";
    }
    this->empty = true;
    player->attack += 5;
    player->defense += 5;
    return "You take the sword and shield from the armory.\n\033[32mATK + 5\nDEF + 5\033[0m";
};

const char* GrandHallRoom::describe() const {
    return "The grand hall stretches before you, with tall, cracked columns reaching toward the vaulted ceiling. A faded red carpet leads from one end of the room to the other, flanked by portraits of stern-faced nobles. The cold, empty space feels oppressive, as though the eyes in the portraits are watching your every move.";
}

const char* CreepyLibraryRoom::describe() const {
    return "You are in a creepy library. Shelves of dusty old books line the walls, and the scent of mildew permeates the air. You hear a soft rustling sound, but can’t tell if it’s just the wind or something more sinister. Cobwebs drape across ancient tomes, their spines too worn to read. Somewhere in this room, knowledge is locked away—but is it worth the risk to search?";
}

const char* SecretPassageRoom::describe() const {
    return "You find yourself in a narrow, twisting passageway, hidden behind a sliding wall. The walls are cold and rough, with barely enough space for you to squeeze through. Every step echoes eerily, making it impossible to tell if someone—or something—is following you. This path wasn’t meant to be found, but maybe it holds the key to your escape.";
}

const char* DungeonCellRoom::describe() const {
    return "You are in a dungeon cell. The room is a cramped, foul-smelling cell. Iron bars stand between you and freedom. Chains hang loosely from the walls, and the remains of what was once a bed lie in the corner, barely more than a pile of rotting straw. A small barred window lets in just enough light to reveal the damp stone walls covered in moss.";
}