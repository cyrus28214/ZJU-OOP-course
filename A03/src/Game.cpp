#include <algorithm>
#include <ctime>
#include <iomanip>
#include "Game.h"
#include "Direction.h"
#include "util.h"
#include "CastleGenerator.h"

// some text constants
const char* ASCII_ART = "    ___       __                 __                \n   /   | ____/ /   _____  ____  / /___  __________ \n  / /| |/ __  / | / / _ \\/ __ \\/ __/ / / / ___/ _ \\\n / ___ / /_/ /| |/ /  __/ / / / /_/ /_/ / /  /  __/\n/_/  |_\\__,_/ |___/\\___/_/ /_/\\__/\\__,_/_/   \\___/ \n     ";

const char* TARGET_AWAY_FROM_MONSTER = "Keep away from the monster.";
const char* TARGET_SAVE_PRINCESS = "Find and save the princess.";
const char* TARGET_LEAVE_THE_CASTLE = "Leave the castle with the princess.";

const char* HELP_TEXT = "Commands:\n - go <DIRECTION>: Move in that direction.\n - target: Check the targets.\n - info: Print player info\n - quit: Quit the game\n - help,?: Show this help message.";

const char* TEXT_BEGIN_JOURNEY = "You stand at the grand entrance of a mysterious castle. The air is thick with silence, and the walls seem to whisper secrets. Somewhere deep inside, a princess awaits rescue, but the castle holds dangers. Only the brave can venture inside and bring her to safety. With every step, the darkness grows stronger. Will you be the hero who saves her? Or will the castle's secrets consume you? Your journey begins now.";
const char* TEXT_WIN = "At last, the castle's entrance comes into view, the faint glow of moonlight spilling through the open doors. You and the princess rush forward, hearts pounding in relief. You've made it. The nightmare is over.\nThe princess turns to you with a grateful smile. \"Thank you. You saved my life,\" she says, her voice trembling with emotion. \"I will never forget your bravery.\"\nAs you step out of the castle's shadow, the weight of your journey lifts. You've succeeded where others have failed. The darkness of the castle fades behind you, but your name will forever be remembered as the one who braved its dangers and saved the princess.\n\033[32mCongratulations!\nYou have win the game!\033[0m";
const char* TEXT_COMPASS = "";
const char* TEXT_MAP = "";


/**
 * @brief Print the ongoing targets
 */
void Game::print_targets() {
    this->out << "Targets:\n";
    for (auto& target : this->targets) { //  for each target in targets
        this->out << " - " << target << "\n";
    }
}

/**
 * @brief Finish a target
 *
 * @param target The target to finish
 * @param quiet If true, don't print a message
 *
 * @throw std::runtime_error("Target not found") if target not found
 */
void Game::finish_target(const char* target, bool quiet) {
    for (auto it = this->targets.begin(); it != this->targets.end(); ++it) { // for each target
        if (*it == target) { // if target found
            if (!quiet) this->out << "\033[32mYou finished a target!\033[0m" << std::endl; // print message if !quiet, ANSI green color
            this->targets.erase(it); // remove the target
            return;
        }
    }
    throw std::runtime_error("Target not found"); // throw error if target not found
}

/**
 * @brief Add a target
 * @param target The target to add, should not be in the target list.
 * @param quiet If true, don't print a message
 */
void Game::add_target(const char* target, bool quiet) {
    this->targets.push_back(target); // add a target
    if (!quiet) this->out << "You have a new target, type \"target\" to check out" << std::endl;
}

/**
 * @brief Print the player info
 */
void Game::print_help() {
    this->out << HELP_TEXT << std::endl;
}

/**
 * @brief run a command typed by player
 * @see Game.cpp::TEXT_HELP
 */
void Game::command(const std::string& cmd) {
    std::string c = trim(cmd); // remove the whitespaces in the beginning and the end of the command
    std::transform(c.begin(), c.end(), c.begin(), ::tolower); // transform the command to lowercase
    std::vector<std::string> tokens = split(c); // split the command into tokens

    // help,?
    if (tokens.size() == 1 && (tokens[0] == "help" || tokens[0] == "?")) {
        this->print_help();
        return;
    }

    // target
    if (tokens.size() == 1 && tokens[0] == "target") {
        this->print_targets();
        return;
    }

    // info
    if (tokens.size() == 1 && tokens[0] == "info") {
        this->print_info();
        return;
    }

    // quit
    if (tokens.size() == 1 && tokens[0] == "quit") {
        this->over();
    }

    // go <DIRECTION>
    if (tokens.size() == 2 && tokens[0] == "go") {
        int x, y, z;
        this->player->get_pos(x, y, z); // get position of the player
        Direction dir = parse_direction(tokens[1].c_str()); // convert string to Direction enum
        std::vector<Direction> exits = this->castle->get_exits(x, y, z); // get all exits connected in the current room
        if (std::find(exits.begin(), exits.end(), dir) != exits.end()) { // check if the direction is valid
            this->player->move(dir); // move to that direction
            if (dir == Direction::UP || dir == Direction::DOWN) {
                this->out << "Go " << stringify_direction(dir) << "stairs." << std::endl;
            }
            else {
                this->out << "Moved to " << stringify_direction(dir) << "." << std::endl;
            }
        }
        else {
            // invalid direction
            this->out << "\033[31mYou can't go that way.\033[0m" << std::endl; // ANSI red color
        }
        return;
    }
    // unkwon command
    this->out << "\033[31mUnknown command.\033[0m" << std::endl; // ANSI red color
}

/**
 * @brief Start the game loop
 */
void Game::start() {
    this->player = new Player(0, 0, 0); // create a player in (0, 0, 0)

    this->out << ASCII_ART << std::endl; // print the title in ASCII art
    this->out << "Welcome to the game Adventure!\n" << std::endl;
    this->out << "Input the seed of the game (leave empty to generate a random one): " << std::flush;
    std::string seed_str;
    int seed;
    std::getline(this->in, seed_str);
    try {
        seed = std::stoi(seed_str);
    }
    catch (std::exception& e) {
        seed = time(nullptr) % 1000000;
    }
    this->out << std::setw(6) << std::setfill('0') << "Use seed \033[32m" << seed << "\033[0m." << std::endl;

    this->castle = CastleGenerator::generate(seed); // generate the castle with seed

    this->out << TEXT_BEGIN_JOURNEY << std::endl;
    this->out << std::endl;
    // add two targets
    this->add_target(TARGET_AWAY_FROM_MONSTER);
    this->add_target(TARGET_SAVE_PRINCESS);
    while (true) {
        int x, y, z;
        this->player->get_pos(x, y, z);
        std::vector<Direction> exits = this->castle->get_exits(x, y, z); // get valid exits
        Castle::RoomPtr current_room = this->castle->get_room(x, y, z); // get the current room
        const char* description = current_room->describe();

        Direction move_to;
        if (current_room->name) {
            this->out << "\t[ " << current_room->name << " ]" << std::endl;
        }
        this->out << description << std::endl;

        if (std::dynamic_pointer_cast<MonsterRoom>(current_room)) { // encounter the monster, the player loses.
            this->out << "\033[31mYou lose.\nGAMEOVER\n\033[0m" << std::endl; // ANSI red color
            this->over();
            return;
        }

        if (!this->princess_saved && std::dynamic_pointer_cast<PrincessRoom>(current_room)) { // take the princess with the player
            std::shared_ptr<PrincessRoom> room = std::dynamic_pointer_cast<PrincessRoom>(current_room);
            this->out << "\033[32mThe princess joined your team!\033[0m" << std::endl; // ANSI green color
            this->finish_target(TARGET_SAVE_PRINCESS);
            this->add_target(TARGET_LEAVE_THE_CASTLE);
            this->princess_saved = true;
            room->princess_in = false;
        }

        if (this->princess_saved && std::dynamic_pointer_cast<LobbyRoom>(current_room)) { // if back to lobby with the princess, the player wins.
            this->out << TEXT_WIN << std::endl;
            this->over();
            return;
        }

        if (std::dynamic_pointer_cast<AbandonedArmoryRoom>(current_room)) { // the palyer can take sword and shield in the armory to increase ATK and DEF
            // however, the ATK and DEF are all useless, because player can't fight with the monster.
            std::shared_ptr<AbandonedArmoryRoom> room = std::dynamic_pointer_cast<AbandonedArmoryRoom>(current_room);
            if (!room->empty) {
                this->out << "Take sword and shield? (y/N): " << std::flush; // ask player to take or not.
                bool yes = this->ask_yes_no();
                if (yes) {
                    this->out << room->take(this->player) << std::endl;
                }
                else {
                    this->out << "You left the sword and shield." << std::endl;
                }
            }
        }

        this->print_room_exits(exits);
        this->out << "What do you want to do (type ? for help): " << std::flush; // ask player to type in command
        std::string cmd;
        std::getline(this->in, cmd);
        this->command(cmd); // run command
        this->out << std::endl;
    }
}

/**
 * @brief print the exits of the current room
 * @param exits the exits of the current room
 */
void Game::print_room_exits(const std::vector<Direction>& exits) {
    if (exits.empty()) {
        this->out << "\033[31mThere is no way out.\033[0m]" << std::endl; // ANSI red color
        return;
    }
    else if (exits.size() == 1) {
        this->out << "There is only one exit: \033[32m" << stringify_direction(exits[0]) << "\033[0m." << std::endl; // ANSI green color
    }
    else {
        this->out << "There are " << exits.size() << " exits: \033[32m"; // ANSI green color
        for (Direction exit : exits) {
            this->out << stringify_direction(exit) << " ";
        }
        this->out << "\033[0m" << std::endl;
    }
}

/**
 * @brief print the player's infomation
 *
 * Example:
 *         #### INFO ####
 * You are at 1F.
 * GOLD: $0
 * HP: 100
 * ATK: 5
 * DEF: 5
 * The princess is still in the castle.
 */
void Game::print_info() {
    int x, y, z;
    this->out << "\t#### INFO ####" << std::endl;
    this->player->get_pos(x, y, z);
    if (z >= 0) { // if in underground, print "You are at -zF."
        this->out << "You are at " << z + 1 << "F." << std::endl; // add 1 to avoid 0 ground
    }
    else {
        this->out << "You are at " << z << "F." << std::endl;
    }
    this->out << "GOLD: $" << this->player->gold << std::endl;
    this->out << "HP: " << this->player->health << std::endl;
    this->out << "ATK: " << this->player->attack << std::endl;
    this->out << "DEF: " << this->player->defense << std::endl;
    if (this->princess_saved) {
        this->out << "\033[32mThe princess is now with you.\033[0m" << std::endl; // ANSI green color
    }
    else {
        this->out << "\033[31mThe princess is still in the castle.\033[0m" << std::endl; // ANSI green color
    }
}

/**
 * @brief exit the game
 */
void Game::over() {
    exit(0);
}

/**
 * @brief ask player to confirm the command
 * if the player confirm, return true, otherwise return false
 * @return true or false
 */
bool Game::ask_yes_no() {
    std::string c;
    std::getline(this->in, c);
    c = trim(c);
    std::transform(c.begin(), c.end(), c.begin(), ::tolower);
    if (c == "yes" || c == "y") {
        return true;
    }
    return false;
}