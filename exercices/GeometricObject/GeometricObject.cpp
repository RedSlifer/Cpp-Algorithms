#include "GeometricObject.h"

GeometricObject::GeometricObject()
{
    this -> color = "white";
    this -> filled = false;
}

GeometricObject::GeometricObject(std::string& color, bool filled)
{
    this -> color = color;
    this -> filled = filled;
}

std::string GeometricObject::get_color() const
{
    return this -> color;
}

void GeometricObject::set_color(const std::string& color)
{
    this -> color = color;
}

bool GeometricObject::is_filled() const
{
    return this -> filled;
}

void GeometricObject::set_filled(bool filled)
{
    this -> filled = filled;
}

std::string GeometricObject::to_string() const
{
    return "Geometric Object";
}
