#include "rectangle.hpp"
#include "debug.hpp"


Rect::Rect(void) {}

Rect::Rect(const unsigned int s) : x(0), y(0), w(s), h(s) {}

Rect::Rect(const unsigned int w, const unsigned int h) : x(0), y(0), w(w), h(h) {}

Rect::Rect(
    const int x,
    const int y,
    const unsigned int w,
    const unsigned int h)
: 
    x(x), y(y), w(w), h(h) {}

Rect::Rect(const Rect &rect)
:
    x(rect.left()), y(rect.top()), w(rect.width()), h(rect.height()) {}


bool Rect::collide(const Vector point) const {
    return (
        (left()   <= point.x) &&
        (right()  >= point.x) &&
        (top()    <= point.y) &&
        (bottom() >= point.y)
    );
}

bool Rect::collide(const Rect rect) const {
    return (
        (this->left() <= rect.right()) &&
        (this->right() >= rect.left()) &&
        (this->top() <= rect.bottom()) && 
        (this->bottom() >= rect.top())
    );
}


void Rect::size(const unsigned int new_width, const unsigned int new_height) {
    w = new_width;
    h = new_height;
}

void Rect::size(const Vector new_size) {
    w = new_size.x;
    h = new_size.y;
}

void Rect::print(void) const {
    std::cout << "Rectangle: [" << left() << ", ";
    std::cout << top() << ", ";
    std::cout << width() << ", ";
    std::cout << height() << "]" << std::endl;
}

void Rect::move(
    const int new_x,
    const int new_y,
    const unsigned int new_width,
    const unsigned int new_height
){
    x = new_x;
    y = new_y;
    w = new_width;
    h = new_height;
}

void Rect::move(const Vector new_topleft, const Vector new_size) {
    size(new_size);
    topleft(new_topleft);
}

void Rect::move(const Rect new_rect) {
    size(new_rect.size());
    topleft(new_rect.topleft());
}


void Rect::draw(const Color color) const {
    DrawRectangle(left(), top(), width(), height(), color);
}