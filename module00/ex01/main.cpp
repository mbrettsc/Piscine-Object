#include "Vector2.hpp"
#include "Graph.hpp"
#include <iostream>

int main() {
    Graph graph(5, 5);

    // Add points
    graph.addPoint(Vector2(0, 0));
    graph.addPoint(Vector2(2, 2));
    graph.addPoint(Vector2(4, 2));
    graph.addPoint(Vector2(2, 4));
    graph.addPoint(Vector2(5, 5));

    // Display graph
    graph.display();

    return 0;
}