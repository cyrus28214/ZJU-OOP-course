#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Castle.h"
#include "Player.h"

/**
 * @brief The class of the game
 */
class Game {
public:
    Game() :in(std::cin), out(std::cout) {};
    Game(std::istream& in, std::ostream& out) : in(in), out(out) {};
    void print_room_exits(const std::vector<Direction>& exits);
    bool ask_yes_no();
    void print_targets();
    void finish_target(const char* target, bool quiet = false);
    void add_target(const char* target, bool quiet = false);
    void print_help();
    void print_info();
    void command(const std::string& cmd);
    void start();
    void over();

    bool princess_saved = false;
private:
    std::istream& in;
    std::ostream& out;
    Player* player;
    Castle* castle;
    std::vector<const char*> targets;
};


#endif // !GAME_H