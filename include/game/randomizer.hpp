
#include "raylib.hpp"
#include "const.hpp"


class Randomizer {

public:
    Randomizer();

    unsigned int roll(unsigned int max_value = ROLL_MAX) const;
    bool roll_bonus(void) const;
};
