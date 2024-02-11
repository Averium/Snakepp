#pragma once

#include "raylib.h"
#include "const.h"
#include "integer_vector.h"


enum celltype{
    EMPTY,
    SNAKE_BODY,
    SNAKE_HEAD,
    APPLE,
};


class Cell{

public:
    Cell();
    Cell(Vector position, celltype type, unsigned int counter);

    void set_state(celltype type, unsigned int counter);
    void set_state(celltype type);

    void update(void);
    void render(Vector position);

    celltype type;
    
    unsigned int counter;

private:
    Vector grid2screen(Vector position);
    Vector grid_position;
};