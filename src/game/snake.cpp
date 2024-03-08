#include "snake.hpp"


Snake::Snake(void) {
    position = Vector(UINT_ZERO, UINT_ZERO);
    direction = DIRECTION::RIGHT;
    length = 1U;
    dead = false;
}


Snake::Snake(Grid* grid, Vector start_pos, unsigned int delay_ms, unsigned int length) : position(start_pos), length(length) {
    set_delay(delay_ms);

    direction = DIRECTION::RIGHT;
    dead = false;
    Cell* cell;

    cell = grid->cell_at(position);
    cell->set_state(SNAKE_HEAD, length - 1);

    for (int i = 1; i < length; i++) {
        Vector target = position - direction * i;
        Cell* cell = grid->cell_at(target);
        cell->set_state(SNAKE_BODY, length - i - 1);
    }
}


unsigned int Snake::get_length(void) const {
    return length;
}


void Snake::increment_length(void) {
    ++length;
}


void Snake::set_dead(void) {
    dead = true;
}


bool Snake::is_dead(void) const {
    return dead;
}


bool Snake::ready_to_move(void) {
    return move_timer.tick();
}


bool Snake::move(bool walls) {
    Vector new_position = position + direction;
    int x = new_position.x;
    int y = new_position.y;

    if (walls && (x > (GRID_COLUMNS - 1) || x < 0 || y > (GRID_ROWS - 1) || y < 0)) {
        return true;
    }

    if (x > GRID_COLUMNS - 1) { new_position.x = 0; }
    if (x < 0) { new_position.x = GRID_COLUMNS - 1; }
    if (y > GRID_ROWS - 1) { new_position.y = 0; }
    if (y < 0) { new_position.y = GRID_ROWS - 1; }

    position = new_position;
    return false;
}


void Snake::turn(Vector new_direction) {
    turn_queue.push(new_direction);
    if (turn_queue.size() > 2) {
        turn_queue.pop();
    }
}


void Snake::change_direction(void) {
    if (turn_queue.size() > UINT_ZERO) {
        Vector new_direction = turn_queue.front();

        if (new_direction != -direction) {
            direction = new_direction;
        }

        turn_queue.pop();
    }
}


void Snake::set_delay(unsigned int delay_ms) {
    move_timer.set((double)(delay_ms) * MS_TO_S);
}