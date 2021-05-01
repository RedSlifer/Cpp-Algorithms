#include <iostream>
#include "GeometricObject.h"
#include "Circle.h"
#include "Rectangle.h"

int main()
{
    GeometricObject geometric_object;
    Circle circle_object;
    Rectangle rectangle_object;

    //std::cout << geometric_object.get_color() << std::endl;
    //std::cout << circle_object.get_color() << std::endl;
    //std::cout << rectangle_object.get_color() << std::endl;

    //geometric_object.set_color("red");
    //circle_object.set_color("grey");
    //rectangle_object.set_color("blue");

    //std::cout << geometric_object.get_color() << std::endl;
    //std::cout << circle_object.get_color() << std::endl;
    //std::cout << rectangle_object.get_color() << std::endl;

    //circle_object.set_radius(4.0);
    rectangle_object.set_height(2.0);
    rectangle_object.set_width(3.0);

    std::cout << circle_object.to_string() << std::endl;
    std::cout << circle_object.get_area() << std::endl;
    std::cout << circle_object.get_perimeter() << std::endl;
    std::cout << circle_object.get_diameter() << std::endl;

    std::cout << std::endl;

    std::cout << rectangle_object.to_string() << std::endl;
    std::cout << rectangle_object.get_height() << std::endl;
    std::cout << rectangle_object.get_width() << std::endl;
    std::cout << rectangle_object.get_area() << std::endl;
    std::cout << rectangle_object.get_perimeter() << std::endl; 

    return 0;
}
