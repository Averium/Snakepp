#pragma once

#include "snake.hpp"


class Score {

public:
    Score();

    void reset(void);

    void increment_apples(void);
    void increment_bonuses(void);

    unsigned int get_apples(void) const;
    unsigned int get_bonuses(void) const;
    unsigned int get_score(void) const;

private:
    unsigned int apples = CONST::UINT_ZERO;
    unsigned int bonuses = CONST::UINT_ZERO;

    static const unsigned int APPLE_MULTIPLIER = CONST::APPLE_MULTIPLIER;
    static const unsigned int BONUS_MULTIPLIER = CONST::BONUS_MULTIPLIER;

};