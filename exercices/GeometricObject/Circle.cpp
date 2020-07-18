#include <cmath>
#include "Circle.h"

Circle::Circle()
{
    this -> radius = 1;
}

Circle::Circle(double radius)
{
    this -> radius = radius;
}

Circle::Circle(double radius, const std::string& color, bool filled)
{
    this -> radius = radius;
    set_color(color);
    set_filled(filled);
}

double Circle::get_radius() const
{
    return this -> radius;
}

void Circle::set_radius(double radius)
{
    this -> radius = radius;
}

double Circle::get_area() const
{
    return M_PI * std::pow(this -> radius, 2);
}

double Circle::get_perimeter() const
{
    return 2 * M_PI * this -> radius;
}

double Circle::get_diameter() const
{
    return 2 * this -> radius;
}

std::string Circle::to_string() const
{
    return "Circle Object";
}
