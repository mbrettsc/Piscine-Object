#include "Graph.hpp"
#include <algorithm>
#include <cairo/cairo.h>
#include <cmath>

Graph::Graph(): size(0, 0) {}

void Graph::addPoint(const Vector2& point)
{
     points.push_back(point);
}

void Graph::saveAsPng(std::string filename) const
{
    int width = static_cast<int>(size.getX()) + 1;
    int height = static_cast<int>(size.getY()) + 1;
    int scale = 50;  // Scale to increase the resolution

    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width * scale, height * scale);
    cairo_t* cr = cairo_create(surface);

    // Set background to white
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    // Draw grid lines
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);  // Light gray
    for (int x = 0; x <= width; ++x) {
        cairo_move_to(cr, x * scale, 0);
        cairo_line_to(cr, x * scale, height * scale);
    }
    for (int y = 0; y <= height; ++y) {
        cairo_move_to(cr, 0, y * scale);
        cairo_line_to(cr, width * scale, y * scale);
    }
    cairo_stroke(cr);

    // Draw points
    cairo_set_source_rgb(cr, 1, 0, 0);  // Red color
    for (std::vector<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it) {
        cairo_arc(cr, it->getX() * scale + scale / 2, (height - it->getY() - 1) * scale + scale / 2, scale / 4, 0, 2 * M_PI);
        cairo_fill(cr);
    }

    // Save to PNG file
    cairo_surface_write_to_png(surface, filename.c_str());

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
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
