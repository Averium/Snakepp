#include "game/cell.hpp"
#include "debug.hpp"


Cell::Cell() {
    set_state(EMPTY);
}


Cell::Cell(
    const Vector position,
    const Vector grid_position,
    const Celltype type,
    const unsigned int counter
) :
    Rect(CELL_SIZE - CELL_GAP * 2)
{
    set_state(type, counter);
    topleft(position * CELL_SIZE + grid_position + Vector(CELL_GAP, CELL_GAP));
}


void Cell::set_state(const Celltype type, const unsigned int counter) {
    this->type = type;
    this->counter = counter;
}


void Cell::set_state(const Celltype type) {
    this->type = type;
    this->counter = UINT_ZERO;
}


void Cell::update(void) {
    if (counter > UINT_ZERO) {
        counter--;
    }
    else if (type == SNAKE_HEAD || type == SNAKE_BODY || type == BONUS) {
        set_state(EMPTY);
    }
    
    if (type == SNAKE_NEW) {
        set_state(SNAKE_HEAD, counter);
    }
    else if (type == SNAKE_HEAD) {
        set_state(SNAKE_BODY, counter);
    }
}


void Cell::render(ColorData& colors, Vector position, Vector forward) const {
    Vector sideway(forward.y, forward.x);
    Rect eye(width() / 3, width() / 3);
    Rect pattern(width() / 2, height() / 2);

    switch (type) {
        case SNAKE_HEAD:
            draw(colors("GREEN2"));
            eye.center(center() + (forward + sideway) * (width() / 4)); eye.draw(colors("GREEN1"));
            eye.center(center() + (forward - sideway) * (width() / 4)); eye.draw(colors("GREEN1"));
            break;

        case SNAKE_BODY:
            draw(colors("GREEN2"));
            pattern.center(center());
            pattern.draw(colors("GREEN1"));
            break;

        case APPLE:
            draw(colors("RED1"));
            break;

        case BONUS:
            draw(colors("BLUE1"));
            break;

        default:
            break;
    }
}