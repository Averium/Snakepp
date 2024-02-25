#include "integer_vector.h"
#include "debug.h"
#include <cmath>


Vector::Vector(void): x(0), y(0) {}
Vector::Vector(int x, int y): x(x), y(y) {}
Vector::Vector(Vector2 vector): x((unsigned int)(vector.x)), y((unsigned int)(vector.y)) {}
Vector::Vector(const Vector &vector): x(vector.x), y(vector.y) {}


float Vector::length(void) const {
    return sqrt((float)(x) * (float)(x) + (float)(y) * (float)(y));
}


Vector2 Vector::vector2(void) const {
    return {(float)(x), (float)(y)};
}


Vector Vector::operator * (int value) const {
    int x = (int)(this->x * value);
    int y = (int)(this->y * value);
    return Vector(x, y);
}


Vector Vector::operator / (int value) const {
    int x = (int)(this->x / value);
    int y = (int)(this->y / value);
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


void Vector::print(void) const {
    std::cout << "Vector: [" << x << ", " << y << "]" << std::endl;
}