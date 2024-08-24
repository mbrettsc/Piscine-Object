#pragma once

#include "Vector2.hpp"
#include <vector>

class Graph
{
private:
    Vector2 size;
    std::vector<Vector2> points;

public:
    Graph();

    void addPoint(const Vector2& point);

    void setSize(Vector2 size) { this->size = size; };

    void display() const;

    void saveAsPng(std::string filename) const;
};
