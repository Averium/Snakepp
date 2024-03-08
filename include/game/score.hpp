#pragma once

#include <string>
#include <vector>

#include "config_data.hpp"
#include "const.hpp"


class Score : public ConfigData<unsigned int> {

public:
    Score();

    void reset(void);

    bool is_highscore(void) const;
    void register_highscore(std::string name);
    void erase_lowest_highscore(void);

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
    static const unsigned int STORED_HIGHSCORES = CONST::STORED_HIGHSCORES;
};
