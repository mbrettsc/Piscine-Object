#include "Vector2.hpp"
#include "Graph.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

void exitError(std::string errMsg)
{
    std::cerr << errMsg << std::endl;
    exit(1);
}

bool onlyAlnum(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isalnum(*it)) {
            return false;
        }
    }
    return true;
}

void readFile(char* fileName, Graph* graph)
{
    std::ifstream is(fileName);
    if (!is.is_open())
        exitError("File open error");
    size_t xm = 0, ym = 0;

    std::string line;
    while (getline(is, line)) {
        std::string sx, sy;
        std::istringstream strIn(line);
        getline(strIn, sx, '/');
        getline(strIn, sy);
        if (onlyAlnum(sx) == false || onlyAlnum(sy) == false)
            exitError("Points are should be in this format; x/x");
        float x = atof(sx.c_str()), y = atof(sy.c_str());
        graph->addPoint(Vector2(x, y));
        if (x > xm)
            xm = x;
        if (y > ym)
            ym = y;
    }
    graph->setSize(Vector2(xm + 1, ym + 1));
}

int main(int ac, char **av) {
    if (ac != 2)
        exitError("This program only accepts argument as a file");
    Graph graph;

    readFile(av[1], &graph);

    graph.display();

    return 0;
}
