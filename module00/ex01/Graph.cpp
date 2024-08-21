#include "Graph.hpp"

void Graph::addPoint(const Vector2& point)
{
    points.push_back(point);
}

void Graph::display() const {
    for (int y = size.getY(); y >= -1; --y) {
        for (int x = 0; x < size.getX(); ++x) {
            std::cout << "& " << y;

        }
        std::cout << std::endl;
        
    }
}