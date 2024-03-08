#include "new_highscore_state.hpp"
#include "game.hpp"


NewHighscoreState::NewHighscoreState(Game* game) : GameState(NEWHIGHSCORE_STATE, game) {}


GameStateId NewHighscoreState::conditions(void) const {
    if (!game->gui->is_focused()) {
        if (game->keyboard.check("Reset", PRESS)) { return GAME_STATE; }
        if (game->keyboard.check("Exit", PRESS)) { return SHUTDOWN_STATE; }
    }
    if (game->newhighscore_done_button->is_clicked()) { return HIGHSCORES_STATE; }
    
    return NEWHIGHSCORE_STATE;
}


void NewHighscoreState::on_entry(void) {
    game->gui->activate_item(game->newhighscore_group);
    game->newhighscore_name_label->clear();
}


void NewHighscoreState::on_exit(void) {
    game->gui->deactivate_item(game->newhighscore_group);

    std::string player_name = game->newhighscore_name_label->get_value();
    if (player_name != "") {
        game->score.register_highscore(player_name);
        game->update_highscores();
    }

    game->reset();
}

void NewHighscoreState::render(void) const {
    game->grid.render_cells(game->snake.direction);
}