#pragma once

#include "config_data.hpp"
#include "const.hpp"


class Score : public ConfigData<unsigned int> {

public:
    Score();

    void reset(void);

    bool is_highscore(void) const;
    void register_player(std::string name);

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


struct SortByValue {
    bool operator()(const unsigned int first, const unsigned int second) const;
};