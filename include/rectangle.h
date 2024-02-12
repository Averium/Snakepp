#pragma once

#include "integer_vector.h"


class Rect {

public:
    Rect();
    Rect(unsigned int w, unsigned int h);
    Rect(int x, int y, unsigned int w, unsigned int h);
    Rect(Rect &rect);

    int width(void) const;
    int height(void) const;

    void left(int);
    void right(int);
    void top(int);
    void bottom(int);
    void centerx(int);
    void centery(int);

    void topleft(Vector);
    void topright(Vector);
    void bottomleft(Vector);
    void bottomright(Vector);
    void center(Vector);
    
    int left(void) const;
    int right(void) const;
    int top(void) const;
    int bottom(void) const;
    int centerx(void) const;
    int centery(void) const;

    Vector topleft(void) const;
    Vector topright(void) const;
    Vector bottomleft(void) const;
    Vector bottomright(void) const;
    Vector center(void) const;

private:
    int x;
    int y;
    unsigned int w;
    unsigned int h;
};