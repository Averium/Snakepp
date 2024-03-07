#include "new_highscore_state.hpp"
#include "game.hpp"


NewHighscoreState::NewHighscoreState(Game* game) : GameState(NEWHIGHSCORE_STATE, game) {}


GameStateId NewHighscoreState::conditions(void) const {
    if (!game->gui->is_focused()) {
        if (game->keyboard.check("Reset", PRESS)) { return GAME_STATE; }
        if (game->keyboard.check("Exit", PRESS)) { return SHUTDOWN_STATE; }
    }
    if (game->newhighscore_restart_button->is_clicked()) { return GAME_STATE; }
    if (game->newhighscore_menu_button->is_clicked()) { return MENU_STATE; }
    
    return NEWHIGHSCORE_STATE;
}


void NewHighscoreState::on_entry(void) {
    game->gui->activate_item(game->newhighscore_group);
    game->newhighscore_name_label->clear();
}


void NewHighscoreState::on_exit(void) {
    game->gui->deactivate_item(game->newhighscore_group);
    game->reset();
}