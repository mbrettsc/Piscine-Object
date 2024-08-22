#pragma once

#include <iostream>

class Vector2
{
private:
    float x;
    float y;
    Vector2();

public:
    Vector2(float x, float y) :
        x(x), y(y) {};

    float getX(void) const { return x; };
    float getY(void) const { return y; };

    void setX(float x) { this->x = x; };
    void setY(float y) { this->y = y; };


    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

};
