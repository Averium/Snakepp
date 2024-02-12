#pragma once


class Vector {

public:
    Vector(void); 
    Vector(int x, int y);

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