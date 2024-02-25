#pragma once

#include "raylib.h"


class Vector {

public:
    Vector(void); 
    Vector(int x, int y);
    Vector(Vector2 vector);
    Vector(const Vector &vector);

    float length(void) const;
    Vector2 vector2(void) const;

    Vector operator * (int value) const;

    Vector operator + (Vector vector) const;
    Vector operator - (Vector vector) const;
    Vector operator - (void) const;

    Vector operator += (Vector vector) const;
    Vector operator -= (Vector vector) const;

    bool operator == (Vector vector) const;
    bool operator != (Vector vector) const;

    int x;
    int y;

private:
};