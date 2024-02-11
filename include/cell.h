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
    Cell(void);
    Cell(celltype type, unsigned int counter);

    void set_state(celltype type, unsigned int counter);
    void set_state(celltype type);

    void update(void);
    void render(unsigned char row, unsigned char col);

    celltype type;
    
    unsigned int counter;

private:
    Vector grid2screen(unsigned char row, unsigned char col);


};