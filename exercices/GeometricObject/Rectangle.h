#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeometricObject.h"

class Rectangle: public GeometricObject
{
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(double width, double height, const std::string& color, bool filled);

public:
    [[nodiscard]] double get_width() const;
    void set_width(double width);
    [[nodiscard]] double get_height() const;
    void set_height(double height);
    [[nodiscard]] double get_area() const;
    [[nodiscard]] double get_perimeter() const;
    [[nodiscard]] std::string to_string() const override;
};

#endif
