#include "score.hpp"


Score::Score() : ConfigData<unsigned int>(PATH::HIGHSCORES) {}


bool Score::is_highscore(void) const {

    unsigned int highest_score = get_score();
    for (const std::pair<std::string, unsigned int>& pair : data) {
        if (pair.second > highest_score) { highest_score = pair.second; }
    }

    return highest_score == get_score();
}


void Score::register_highscore(const std::string player_name) {
    data.insert({ player_name, get_score() });

    if (data.size() > STORED_HIGHSCORES) { erase_lowest_highscore(); }
    save();
}


void Score::erase_lowest_highscore(void) {
    std::pair<std::string, unsigned int> lowest_element = {"", UINT_MAX};

    for (const std::pair<std::string, unsigned int>& pair : data) {
        if (pair.second < lowest_element.second) { lowest_element = pair; }
    }

    data.erase(lowest_element.first);
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
