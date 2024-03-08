#include "score.hpp"


Score::Score() : ConfigData<unsigned int>(PATH::HIGHSCORES) {}


bool Score::is_highscore(void) const {

    unsigned int highest_score = get_score();
    if (highest_score == UINT_ZERO) { return false; }

    for (const std::pair<std::string, unsigned int>& pair : data) {
        if (pair.second > highest_score) { highest_score = pair.second; }
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

    for (const std::pair<std::string, unsigned int>& pair : data) {
        if (pair.second < lowest_element.second) { lowest_element = pair; }
    }

    data.erase(lowest_element.first);
}


std::array<std::string, STORED_HIGHSCORES> Score::sorted_keys(void) {

    std::array<std::string, STORED_HIGHSCORES> keys;
    std::pair<std::string, unsigned int> items[STORED_HIGHSCORES];
    std::pair<std::string, unsigned int> temp;

    int index = UINT_ZERO;

    for (const std::pair<std::string, unsigned int>& pair : data) {
        items[index++] = pair;
    }

    for (index = UINT_ONE; index < STORED_HIGHSCORES; index++) {
        if (items[index].second > items[index - UINT_ONE].second) {

            temp = items[index];
            items[index] = items[index - UINT_ONE];
            items[index - UINT_ONE] = temp;

            index = UINT_ZERO;
        }
    }

    for (index = UINT_ZERO; index < STORED_HIGHSCORES; index++) {
        keys[index] = items[index].first;
    }

    return keys;
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
