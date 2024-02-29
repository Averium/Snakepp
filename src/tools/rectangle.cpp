#include "rectangle.hpp"
#include "debug.hpp"


Rect::Rect(void) {}

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

bool Rect::collide(Vector point) {
    return (
        (left() <= point.x)  &&
        (right() >= point.x) &&
        (top() <= point.y)   &&
        (bottom() >= point.y)
    );
}

bool Rect::collide(Rect rect) {
    return (
        (this->left() <= rect.right()) &&
        (this->right() >= rect.left()) &&
        (this->top() <= rect.bottom()) && 
        (this->bottom() >= rect.top())
    );
}

void Rect::width(unsigned int new_width)   { w = new_width; }
void Rect::height(unsigned int new_height) { h = new_height; }

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


void Rect::print(void) const {
    std::cout << "Rectangle: [" << left() << ", ";
    std::cout << top() << ", ";
    std::cout << width() << ", ";
    std::cout << height() << "]" << std::endl;
}
