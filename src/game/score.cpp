#include "score.hpp"


Score::Score() : ConfigData<unsigned int>(PATH::HIGHSCORES) {}


bool Score::is_highscore(void) const {

    unsigned int highest_score = get_score();
    for (const std::pair<std::string, unsigned int>& pair : data) {
        if (pair.second > highest_score) { highest_score = pair.second; }
    }

    return highest_score == get_score();
}


void Score::register_player(const std::string name) {
    data[name] = get_score();
    if (data.size() > STORED_HIGHSCORES) { data.erase(data.begin()); }

    save();
}


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


bool SortByValue::operator()(const unsigned int first, const unsigned int second) const {
    return first < second;
};