#pragma once

#include "raylib.h"
#include "const.h"
#include <vector>


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

    void update(void);
    void render(unsigned char row, unsigned char col);

    celltype type; 

private:
    std::vector<unsigned int> grid2screen(unsigned char row, unsigned char col);

    unsigned int counter;
    
};