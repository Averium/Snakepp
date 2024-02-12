#include "rectangle.h"


Rect::Rect() {}

Rect::Rect(int w, int h) {
    this->w = w;
    this->h = h;
}

Rect::Rect(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

inline void Rect::topleft(Vector vector) {
    top(vector.y);
    left(vector.x);
}

inline void Rect::topright(Vector vector) {
    top(vector.y);
    right(vector.x);
}

inline void Rect::bottomleft(Vector vector) {
    bottom(vector.y);
    left(vector.x);
}

inline void Rect::bottomright(Vector vector) {
    bottom(vector.y);
    right(vector.x);
}

inline void Rect::center(Vector vector) {
    centerx(vector.x);
    centery(vector.y);
}

inline void Rect::left(int value)           { x = value; }
inline void Rect::right(int value)          { x = value - w; }
inline void Rect::top(int value)            { y = value; }
inline void Rect::bottom(int value)         { y = value - h; }
inline void Rect::centerx(int value)        { x = value - w / 2; }
inline void Rect::centery(int value)        { y = value - h / 2; }

inline int Rect::left(void) const           { return x; }
inline int Rect::right(void) const          { return x + w; }
inline int Rect::top(void) const            { return y; }
inline int Rect::bottom(void) const         { return y + h; }
inline int Rect::centerx(void) const        { return x + w / 2; }
inline int Rect::centery(void) const        { return y + h / 2; }

inline Vector Rect::topleft(void) const     { return Vector(top(), left()); }
inline Vector Rect::topright(void) const    { return Vector(top(), right()); }
inline Vector Rect::bottomleft(void) const  { return Vector(bottom(), left()); }
inline Vector Rect::bottomright(void) const { return Vector(bottom(), left()); }
inline Vector Rect::center(void) const      { return Vector(centerx(), centery()); }
