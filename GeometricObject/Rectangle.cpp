#include "Rectangle.h"

Rectangle::Rectangle() {
    this -> width = 1;
    this -> height = 1;
}

Rectangle::Rectangle(double width, double height) {
    this -> width = width;
    this -> height = height;
}

Rectangle::Rectangle(double width, double height, const std::string& color, bool filled) {
    this -> width = width;
    this -> height = height;
    set_color(color);
    set_filled(filled);
}

double Rectangle::get_width() const {
    return this -> width;
}

void Rectangle::set_width(double width) {
    this -> width = width;
}

double Rectangle::get_height() const {
    return this -> height;
}

void Rectangle::set_height(double height) {
    this -> height = height;
}

double Rectangle::get_area() const {
    return (this -> width) * (this -> height);
}

double Rectangle::get_perimeter() const {
    return (2 * (this -> width)) + (2 * (this -> height));
}

std::string Rectangle::to_string() const {
    return "Rectangle Object";
}
