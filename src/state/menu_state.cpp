#include "menu_state.hpp"
#include "game.hpp"


MenuState::MenuState(
    Game* game
) :
    GuiState(MENU_STATE, game, game->menu_group)
{}


GameStateId MenuState::conditions(void) const {
    if (game->menu_start_button->is_clicked()) { return BEGIN_STATE; }
    if (game->menu_settings_button->is_clicked()) { return SETTINGS_STATE; }
    if (game->menu_keybinds_button->is_clicked()) { return KEYBINDS_STATE; }
    if (game->menu_highscores_button->is_clicked()) { return HIGHSCORES_STATE; }
    if (game->menu_about_button->is_clicked()) { return ABOUT_STATE; }
    if (game->menu_exit_button->is_clicked()) { return SHUTDOWN_STATE; }

    if (game->keyboard.check("Exit", PRESS)) { return SHUTDOWN_STATE; }
    
    return MENU_STATE;
}