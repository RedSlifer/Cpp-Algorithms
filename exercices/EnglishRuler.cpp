#include <iostream>

void draw_one_tick(int tick_length, int tick_label = -1);
void draw_ticks(int tick_length);
void draw_ruler(int number_inches, int major_length);

int main()
{
    draw_ruler(2, 4);

    return 0;
}

void draw_one_tick(int tick_length, int tick_label)
{
    int i;

    if (tick_label >= 0)
    {
        for (i = 0; i < tick_length; i++)
        {
            std::cout << "-";
        }
        std::cout << " " << tick_label;
        std::cout << std::endl;
    }
    else
    {
        for (i = 0; i < tick_length; i++)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

void draw_ticks(int tick_length)
{
    if (tick_length > 0)
    {
        draw_ticks(tick_length - 1);
        draw_one_tick(tick_length);
        draw_ticks(tick_length - 1);
    }
}

void draw_ruler(int number_inches, int major_length)
{
    int i;

    draw_one_tick(major_length, 0);

    for (i = 1; i <= number_inches; i++)
    {
        draw_ticks(major_length - 1);
        draw_one_tick(major_length, i);
    }
}
