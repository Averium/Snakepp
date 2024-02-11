#pragma once


class Vector {

public:
    Vector(void); 
    Vector(int x, int y);

    Vector operator + (Vector vector);
    Vector operator - (Vector vector);
    void operator += (Vector vector);
    void operator -= (Vector vector);

    int x;
    int y;

private:
};