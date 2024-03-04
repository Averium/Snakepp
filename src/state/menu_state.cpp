#include "menu_state.hpp"
#include "game.hpp"


MenuState::MenuState(Game* game) : GameState(MENU_STATE, game) {}


GameStateId MenuState::conditions(void) const {
    if (game->menu_start_button->is_clicked()) { return GAME_STATE; }
    if (game->menu_settings_button->is_clicked()) { return SETTINGS_STATE; }
    if (game->menu_keybinds_button->is_clicked()) { return KEYBINDS_STATE; }
    if (game->menu_highscores_button->is_clicked()) { return HIGHSCORES_STATE; }
    if (game->menu_exit_button->is_clicked()) { return SHUTDOWN_STATE; }

    if (game->keyboard.check("EXIT", PRESS)) { return SHUTDOWN_STATE; }
    
    return MENU_STATE;
}


void MenuState::on_entry(void) {
    game->gui->activate_item(game->menu_group);
    game->reset();
}


void MenuState::on_exit(void) {
    game->gui->deactivate_item(game->menu_group);
}
