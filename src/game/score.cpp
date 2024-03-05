#include "score.hpp"


Score::Score() {}


void Score::reset(void) {
    this->apples = CONST::UINT_ZERO;
    this->bonuses = CONST::UINT_ZERO;
}


void Score::increment_apples(void) {
    ++apples;
}


void Score::increment_bonuses(void) {
    ++bonuses;
}


unsigned int Score::get_apples(void) const {
    return apples;
}


unsigned int Score::get_bonuses(void) const {
    return bonuses;
}


unsigned int Score::get_score(void) const {
    return (unsigned int)(apples * APPLE_MULTIPLIER + bonuses * BONUS_MULTIPLIER); 
}



