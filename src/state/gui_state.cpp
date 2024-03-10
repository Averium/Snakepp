#include "gui_state.hpp"
#include "game.hpp"


GuiState::GuiState(
    GameStateId id,
    Game* game,
    WidgetGroup* widget_group
) :
    GameState(id, game),
    widget_group(widget_group)
{}


void GuiState::on_entry(void) {
    game->gui->activate_item(widget_group);
}


void GuiState::on_exit(void) {
    game->gui->deactivate_item(widget_group);
}
