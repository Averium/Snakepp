#include "rectangle.h"


Rect::Rect() {}

Rect::Rect(unsigned int w, unsigned int h) {
    this->x = 0;
    this->y = 0;
    this->w = w;
    this->h = h;
}

Rect::Rect(int x, int y, unsigned int w, unsigned int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}


Rect::Rect(Rect &rect) {
    this->x = rect.left();
    this->y = rect.top();
    this->w = rect.width();
    this->h = rect.height();
}


int Rect::width(void) const  { return w; }
int Rect::height(void) const { return h; }

void Rect::topleft(Vector vector) {
    top(vector.y);
    left(vector.x);
}

void Rect::topright(Vector vector) {
    top(vector.y);
    right(vector.x);
}

void Rect::bottomleft(Vector vector) {
    bottom(vector.y);
    left(vector.x);
}

void Rect::bottomright(Vector vector) {
    bottom(vector.y);
    right(vector.x);
}

void Rect::center(Vector vector) {
    centerx(vector.x);
    centery(vector.y);
}

void Rect::left(int value)           { x = value; }
void Rect::right(int value)          { x = value - w; }
void Rect::top(int value)            { y = value; }
void Rect::bottom(int value)         { y = value - h; }
void Rect::centerx(int value)        { x = value - w / 2; }
void Rect::centery(int value)        { y = value - h / 2; }

int Rect::left(void) const           { return x; }
int Rect::right(void) const          { return x + w; }
int Rect::top(void) const            { return y; }
int Rect::bottom(void) const         { return y + h; }
int Rect::centerx(void) const        { return x + w / 2; }
int Rect::centery(void) const        { return y + h / 2; }

Vector Rect::topleft(void) const     { return Vector(top(), left()); }
Vector Rect::topright(void) const    { return Vector(top(), right()); }
Vector Rect::bottomleft(void) const  { return Vector(bottom(), left()); }
Vector Rect::bottomright(void) const { return Vector(bottom(), left()); }
Vector Rect::center(void) const      { return Vector(centerx(), centery()); }
