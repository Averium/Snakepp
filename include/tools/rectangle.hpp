#pragma once

#include "integer_vector.hpp"


class Rect {

public:
    Rect();
    Rect(const unsigned int s);
    Rect(const unsigned int w, const unsigned int h);
    Rect(const int x, const int y, const unsigned int w, const unsigned int h);
    Rect(const Rect &rect);

    bool collide(const Vector point) const;
    bool collide(const Rect rect) const;

    inline void width(const unsigned int new_width)   { w = new_width; }
    inline void height(const unsigned int new_height) { h = new_height; }
    
    void size(const unsigned int, const unsigned int);
    void size(const Vector);

    void move(const int, const int, const unsigned int, const unsigned int);
    void move(const Vector, const Vector);
    void move(const Rect);

    inline void left(const int value)    { x = value; }
    inline void right(const int value)   { x = value - w; }
    inline void top(const int value)     { y = value; }
    inline void bottom(const int value)  { y = value - h; }
    inline void centerx(const int value) { x = value - w / 2; }
    inline void centery(const int value) { y = value - h / 2; }

    void center(const int x, const int y) { centerx(x); centery(y); }
    void center(const Vector vector)      { centerx(vector.x); centery(vector.y); }

    inline int width(void) const   { return w; }
    inline int height(void) const  { return h; }
    inline Vector size(void) const { return Vector(w, h); }

    inline void topleft(const Vector vector)          { top(vector.y); left(vector.x); }
    inline void topleft(const int x, const int y)     { top(y); left(x); }
    inline void topright(const Vector vector)         { top(vector.y); right(vector.x); }
    inline void topright(const int x, const int y)    { top(y); right(x); }
    inline void bottomleft(const int x, const int y)  { bottom(y); left(x); }
    inline void bottomleft(const Vector vector)       { bottom(vector.y); left(vector.x); }
    inline void bottomright(const int x, const int y) { bottom(y); right(x); }
    inline void bottomright(const Vector vector)      { bottom(vector.y); right(vector.x); }
    inline void midleft(const Vector vector)          { centery(vector.y); left(vector.x); }
    inline void midleft(const int x, const int y)     { centery(y); left(x); }
    inline void midright(const Vector vector)         { centery(vector.y); right(vector.x); }
    inline void midright(const int x, const int y)    { centery(y); right(x); }
    inline void midtop(const int x, const int y)      { centerx(x); top(y); }
    inline void midtop(const Vector vector)           { centerx(vector.x); top(vector.y); }
    inline void midbottom(const int x, const int y)   { centerx(x); bottom(y); }
    inline void midbottom(const Vector vector)        { centerx(vector.x); bottom(vector.y); }
    
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
    void draw(const Color color) const;

private:
    int x;
    int y;
    unsigned int w;
    unsigned int h;
};