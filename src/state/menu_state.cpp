#include "menu_state.hpp"
#include "game.hpp"


MenuState::MenuState(Game* game) : GameState(MENU, game) {}

GameStateId MenuState::conditions(void) const {
    if (game->menu_start_button->is_clicked()) { return GAME; }
    if (game->menu_settings_button->is_clicked()) { return SETTINGS; }
    if (game->menu_keybinds_button->is_clicked()) { return KEYBINDS; }
    if (game->menu_highscores_button->is_clicked()) { return HIGHSCORES; }
    if (game->menu_exit_button->is_clicked()) { return SHUTDOWN; }

    if (game->key_handler.check(KEY_ESCAPE, PRESS)) { return SHUTDOWN; }
    
    return MENU;
}


void MenuState::on_entry(void) {
    game->gui->activate_item(game->menu_group);
}


void MenuState::on_exit(void) {
    game->gui->deactivate_item(game->menu_group);
}
