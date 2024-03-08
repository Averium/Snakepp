#include "score.hpp"


Score::Score() : ConfigData<unsigned int>(PATH::HIGHSCORES) {}


bool Score::is_highscore(void) const {

    unsigned int highest_score = get_score();
    if (highest_score == UINT_ZERO) { return false; }

    for (const auto& pair : data) {
        highest_score = pair.second > highest_score ? pair.second : highest_score;
    }

    return highest_score == get_score();
}


void Score::register_highscore(const std::string player_name) {

    data[player_name] = get_score();
    if (data.size() > STORED_HIGHSCORES) { erase_lowest_highscore(); }

    save();
}


void Score::erase_lowest_highscore(void) {

    std::pair<std::string, unsigned int> lowest_element = {"", UINT_MAX};
    for (const auto& pair : data) {
        if (pair.second < lowest_element.second) { lowest_element = pair; }
    }

    data.erase(lowest_element.first);
}


std::array<std::pair<std::string, unsigned int>, STORED_HIGHSCORES> Score::sorted_pairs(void) const {

    std::array<std::pair<std::string, unsigned int>, STORED_HIGHSCORES> items;
    std::pair<std::string, unsigned int> temp;

    int index = UINT_ZERO;

    for (const auto& pair : data) { items[index++] = pair; }

    for (index = UINT_ONE; index < STORED_HIGHSCORES; index++) {
        if (items[index].second > items[index - UINT_ONE].second) {
            std::swap(items[index], items[index - UINT_ONE]);
            index = UINT_ZERO;
        }
    }

    return items;
}


void Score::reset(void) {
    this->apples = UINT_ZERO;
    this->bonuses = UINT_ZERO;
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
