#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>

class GeometricObject
{
private:
    std::string color;
    bool filled;

public:
    GeometricObject();
    GeometricObject(std::string& color, bool filled);

public:
    [[nodiscard]] std::string get_color() const;
    void set_color(const std::string& color);
    [[nodiscard]] bool is_filled() const;
    void set_filled(bool filled);
    [[nodiscard]] virtual std::string to_string() const;
};

#endif
