#include <iostream>
#include <cmath>

int main() {
    int radius;
    double point_1_x, point_1_y, point_2_x, point_2_y, point_3_x, point_3_y, point_4_x, point_4_y, point_5_x, point_5_y; 
    double angle = 0.628319;

    std::cin >> radius;

    point_1_x = 0.0;
    point_1_y = radius;
    
    point_2_x = radius * cos(angle * 2);
    point_2_y = radius * sin(angle * 2);

    point_3_x = radius * cos(angle);
    point_3_y = (radius * sin(angle)) * -1;

    point_4_x = point_3_x * -1;
    point_4_y = point_3_y;

    point_5_x = (radius * cos(angle * 2)) * -1;
    point_5_y = radius * sin(angle * 2);

    std::cout << point_1_x << " " << point_1_y << std::endl;
    std::cout << point_2_x << " " << point_2_y << std::endl;
    std::cout << point_3_x << " " << point_3_y << std::endl;
    std::cout << point_4_x << " " << point_4_y << std::endl;
    std::cout << point_5_x << " " << point_5_y << std::endl;
    
    return 0;
}
