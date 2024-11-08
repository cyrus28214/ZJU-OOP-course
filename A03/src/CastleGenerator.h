#ifndef CASTLE_GENERATOR
#define CASTLE_GENERATOR

#include "Castle.h"

/**
 * @brief Generates a random castle.
 */
class CastleGenerator {
public:
    static Castle* generate(unsigned int seed);
};

#endif // !CASTLE_GANERATOR