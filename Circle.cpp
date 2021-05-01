#include <iostream>

class Circle
{
    public:
        // Data field
        double radius;
        
        // Construct a default circle object
        Circle()
        {
            radius = 1;
        }
        
        // Construct a circle object
        Circle(double new_radius)
        {
            radius = new_radius;
        }

        // Return the area of this circle
        double get_area()
        {
            return radius * radius * 3.14159;
        }
};

int main()
{
    Circle circle_1(1.0);
    Circle circle_2(25);
    Circle circle_3(125);

    std::cout << circle_1.radius << " " << circle_1.get_area() << std::endl;
    std::cout << circle_2.radius << " " << circle_2.get_area() << std::endl;
    std::cout << circle_3.radius << " " << circle_3.get_area() << std::endl;
    std::cout << std::endl;

    circle_1.radius = 100;
    std::cout << circle_1.radius << " " << circle_1.get_area() << std::endl;

    return 0;
}