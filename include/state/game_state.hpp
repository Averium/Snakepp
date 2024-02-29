#pragma once

#include "state.hpp"


class Game;


class GameState: public State {

public:
    inline GameState(GameStateId id, Game* game) : State(id, nullptr), game(game) {}

    virtual void events(void) {};
    virtual void update(void) {};
    virtual void render(void) {};

protected:
    Game* game;

};