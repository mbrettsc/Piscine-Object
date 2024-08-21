#pragma once

#include "Vector2.hpp"
#include <vector>

class Graph
{
private:
    Vector2 size;
    std::vector<Vector2> points;

public:
    Graph(float width, float height) : size(width, height) {}

    void addPoint(const Vector2& point);

    void display() const;
};
