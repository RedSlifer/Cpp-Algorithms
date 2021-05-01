#ifndef CIRCLE_H
#define CIRCLE_H
#include "GeometricObject.h"

class Circle: public GeometricObject
{
private:
    double radius;

public:
    Circle();
    Circle(double radius);
    Circle(double radius, const std::string& color, bool filled);

public:
    [[nodiscard]] double get_radius() const;
    void set_radius(double radius);
    [[nodiscard]] double get_area() const;
    [[nodiscard]] double get_perimeter() const;
    [[nodiscard]] double get_diameter() const;
    [[nodiscard]] std::string to_string() const override;
};

#endif
