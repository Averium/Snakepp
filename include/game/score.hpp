#pragma once

#include <string>
#include <array>

#include "config_data.hpp"
#include "const.hpp"


class Score : public ConfigData<unsigned int> {

public:
    Score();

    void reset(void);

    bool is_highscore(void) const;
    void register_highscore(std::string name);
    void erase_lowest_highscore(void);

    std::array<std::string, STORED_HIGHSCORES> sorted_keys(void);

    void increment_apples(void);
    void increment_bonuses(void);

    unsigned int get_apples(void) const;
    unsigned int get_bonuses(void) const;
    unsigned int get_score(void) const;

private:
    unsigned int apples = UINT_ZERO;
    unsigned int bonuses = UINT_ZERO;
};
