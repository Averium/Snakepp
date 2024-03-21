#pragma once

#include "state.hpp"


class Game;


class GameState: public State {

public:
    inline GameState(GameStateId id, Game* game) : State(id, nullptr), game(game) {}

    inline virtual void events(void) {};
    inline virtual void update(void) {};
    inline virtual void render(ColorData& colors) const {};

protected:
    Game* game;

};