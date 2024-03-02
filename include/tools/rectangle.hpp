#pragma once

#include "integer_vector.hpp"


class Rect {

public:
    Rect();
    Rect(unsigned int w, unsigned int h);
    Rect(int x, int y, unsigned int w, unsigned int h);
    Rect(Rect &rect);

    bool collide(Vector point);
    bool collide(Rect rect);

    inline void width(unsigned int new_width)   { w = new_width; }
    inline void height(unsigned int new_height) { h = new_height; }
    
    void size(unsigned int, unsigned int);
    void size(Vector);

    void move(int, int, unsigned int, unsigned int);
    void move(Vector, Vector);
    void move(Rect);

    inline void left(int value)    { x = value; }
    inline void right(int value)   { x = value - w; }
    inline void top(int value)     { y = value; }
    inline void bottom(int value)  { y = value - h; }
    inline void centerx(int value) { x = value - w / 2; }
    inline void centery(int value) { y = value - h / 2; }

    void center(int x, int y) { centerx(x); centery(y); }
    void center(Vector vector) { centerx(vector.x); centery(vector.y); }

    inline int width(void) const   { return w; }
    inline int height(void) const  { return h; }
    inline Vector size(void) const { return Vector(w, h); }

    inline void topleft(Vector vector)     { top(vector.y); left(vector.x); }
    inline void topleft(int x, int y)      { top(y); left(x); }
    inline void topright(Vector vector)    { top(vector.y); right(vector.x); }
    inline void topright(int x, int y)     { top(y); right(x); }
    inline void bottomleft(int x, int y)   { bottom(y); left(x); }
    inline void bottomleft(Vector vector)  { bottom(vector.y); left(vector.x); }
    inline void bottomright(int x, int y)  { bottom(y); right(x); }
    inline void bottomright(Vector vector) { bottom(vector.y); right(vector.x); }
    inline void midleft(Vector vector)     { centery(vector.y); left(vector.x); }
    inline void midleft(int x, int y)      { centery(y); left(x); }
    inline void midright(Vector vector)    { centery(vector.y); right(vector.x); }
    inline void midright(int x, int y)     { centery(y); right(x); }
    inline void midtop(int x, int y)       { centerx(x); top(y); }
    inline void midtop(Vector vector)      { centerx(vector.x); top(vector.y); }
    inline void midbottom(int x, int y)    { centerx(x); bottom(y); }
    inline void midbottom(Vector vector)   { centerx(vector.x); bottom(vector.y); }
    
    inline int left(void) const    { return x; }
    inline int right(void) const   { return x + w; }
    inline int top(void) const     { return y; }
    inline int bottom(void) const  { return y + h; }
    inline int centerx(void) const { return (int)(x + w / 2); }
    inline int centery(void) const { return (int)(y + h / 2); }

    inline Vector topleft(void) const     { return Vector(left(), top()); }
    inline Vector topright(void) const    { return Vector(right(), top()); }
    inline Vector bottomleft(void) const  { return Vector(left(), bottom()); }
    inline Vector bottomright(void) const { return Vector(right(), bottom()); }
    inline Vector midleft(void) const     { return Vector(left(), centery()); }
    inline Vector midright(void) const    { return Vector(right(), centery()); }
    inline Vector midtop(void) const      { return Vector(centerx(), top()); }
    inline Vector midbottom(void) const   { return Vector(centerx(), bottom()); }
    inline Vector center(void) const      { return Vector(centerx(), centery()); }

    void print(void) const;

private:
    int x;
    int y;
    unsigned int w;
    unsigned int h;
};