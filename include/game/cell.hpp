#pragma once

#include "raylib.hpp"
#include "const.hpp"
#include "rectangle.hpp"


enum celltype{
    EMPTY,
    SNAKE_BODY,
    SNAKE_HEAD,
    SNAKE_NEW,
    APPLE,
};


class Cell : public Rect {

public:
    Cell();
    Cell(const Vector position, const Vector grid_position, const celltype type, const unsigned int counter);

    void set_state(const celltype type, const unsigned int counter);
    void set_state(const celltype type);

    void update(void);
    void render(const Vector position, const Vector forward) const;

    celltype type;
    unsigned int counter;

private:
    Rect pattern;
};