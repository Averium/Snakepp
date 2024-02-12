#pragma once

#include "integer_vector.h"


class Rect {

public:
    Rect();
    Rect(int w, int h);
    Rect(int x, int y, int w, int h);

    inline void left(int);
    inline void right(int);
    inline void top(int);
    inline void bottom(int);
    inline void centerx(int);
    inline void centery(int);

    inline void topleft(Vector);
    inline void topright(Vector);
    inline void bottomleft(Vector);
    inline void bottomright(Vector);
    inline void center(Vector);
    
    inline int left(void) const;
    inline int right(void) const;
    inline int top(void) const;
    inline int bottom(void) const;
    inline int centerx(void) const;
    inline int centery(void) const;

    inline Vector topleft(void) const;
    inline Vector topright(void) const;
    inline Vector bottomleft(void) const;
    inline Vector bottomright(void) const;
    inline Vector center(void) const;

private:
    int x;
    int y;
    int w;
    int h;
};