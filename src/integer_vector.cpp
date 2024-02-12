#include "integer_vector.h"


Vector::Vector(void) {
    this->x = 0;
    this->y = 0;
}


Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}


Vector Vector::operator * (int value) const {
    int x = (int)(this->x * value);
    int y = (int)(this->y * value);
    return Vector(x, y);
}


Vector Vector::operator + (Vector vector) const {
    int x = this->x + vector.x;
    int y = this->y + vector.y;
    return Vector(x, y);
}


Vector Vector::operator - (Vector vector) const {
    int x = this->x - vector.x;
    int y = this->y - vector.y;
    return Vector(x, y);
}


Vector Vector::operator += (Vector vector) const {
    int x = this->x + vector.x;
    int y = this->y + vector.y;
    return Vector(x, y);
}


Vector Vector::operator -= (Vector vector) const {
    int x = this->x - vector.x;
    int y = this->y - vector.y;
    return Vector(x, y);
}


Vector Vector::operator - (void) const {
    return Vector(-this->x, -this->y);
}


bool Vector::operator == (Vector vector) const {
    return (this->x == vector.x && this->y == vector.y);
}


bool Vector::operator != (Vector vector) const {
    return (this->x != vector.x || this->y != vector.y);
}