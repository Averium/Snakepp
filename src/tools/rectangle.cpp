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


void Rect::size(unsigned int new_width, unsigned int new_height) {
    w = new_width;
    h = new_height;
}

void Rect::size(Vector new_size) {
    w = new_size.x;
    h = new_size.y;
}

void Rect::print(void) const {
    std::cout << "Rectangle: [" << left() << ", ";
    std::cout << top() << ", ";
    std::cout << width() << ", ";
    std::cout << height() << "]" << std::endl;
}

void Rect::move(int new_x, int new_y, unsigned int new_width, unsigned int new_height) {
    x = new_x;
    y = new_y;
    w = new_width;
    h = new_height;
}

void Rect::move(Vector new_topleft, Vector new_size) {
    size(new_size);
    topleft(new_topleft);
}

void Rect::move(Rect new_rect) {
    size(new_rect.size());
    topleft(new_rect.topleft());
}