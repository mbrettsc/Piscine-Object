#include "Graph.hpp"
#include <algorithm>

Graph::Graph(): size(0, 0) {}

void Graph::addPoint(const Vector2& point)
{
     points.push_back(point);
}

void Graph::display() const {
    for (int y = size.getY(); y >= -1; --y) {
        std::cout << "& ";
        if (y != -1)
            std::cout << y;
        else
            std::cout << " ";
        for (int x = 0; x <= size.getX(); ++x) {
            if (y != -1)
            {
                if (std::find(points.begin(), points.end(), Vector2(x, y)) != points.end())
                    std::cout << " X";
                else
                    std::cout << " .";
            }
            else
                std::cout << " " << x;
        }
        std::cout << std::endl;

    }
}
