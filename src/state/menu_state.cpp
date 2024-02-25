#include "menu_state.h"
#include "game.h"


MenuState::MenuState(Game* game) : GameState(MENU, game) {}

GameStateId MenuState::conditions(void) const {
    if (game->start_button->is_clicked()) {
        return GAME;
    }
    return MENU;
}


void MenuState::on_entry(void) {
    game->gui->activate_item(game->menu_group);
}


void MenuState::on_exit(void) {
    game->gui->deactivate_item(game->menu_group);
}