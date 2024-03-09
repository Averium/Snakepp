#include "randomizer.hpp"
#include "debug.hpp"


Randomizer::Randomizer() {}


unsigned int Randomizer::roll(unsigned int max_value) const {
    return (unsigned int)(GetRandomValue(UINT_ZERO, max_value));
}


bool Randomizer::roll_bonus(void) const {
    return roll() < ROLL_BONUS_CHANCE;
}
