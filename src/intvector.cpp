#include "intvector.h"


Vector::Vector(void) {
    this->x = 0;
    this->y = 0;
}


Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}


Vector Vector::operator + (Vector vector) {
    int x = this->x + vector.x;
    int y = this->y + vector.y;
    return Vector(x, y);
}


Vector Vector::operator - (Vector vector) {
    int x = this->x - vector.x;
    int y = this->y - vector.y;
    return Vector(x, y);
}


void Vector::operator += (Vector vector) {
    this->x += vector.x;
    this->y += vector.y;
}


void Vector::operator -= (Vector vector) {
    this->x -= vector.x;
    this->y -= vector.y;
}