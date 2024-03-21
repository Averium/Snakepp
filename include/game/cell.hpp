#pragma once

#include "raylib.hpp"
#include "const.hpp"
#include "rectangle.hpp"


enum Celltype{
    EMPTY,
    SNAKE_BODY,
    SNAKE_HEAD,
    SNAKE_NEW,
    APPLE,
    BONUS,
};


class Cell : public Rect {

public:
    Cell();
    Cell(const Vector position, const Vector grid_position, const Celltype type, const unsigned int counter);

    void set_state(const Celltype type, const unsigned int counter);
    void set_state(const Celltype type);

    void update(void);
    void render(ColorData& colors, const Vector position, const Vector forward) const;

    Celltype type;
    unsigned int counter;

private:
    Rect pattern;
};