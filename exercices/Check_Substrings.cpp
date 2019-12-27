#include <iostream>

int check_substring(const std::string& string_1, const std::string& string_2)
{
    size_t index;

    index = string_2.find(string_1);

    if (index != std::string::npos)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::string string_1;
    std::string string_2;

    std::getline(std::cin, string_1);
    std::getline(std::cin, string_2);

    std::cout << check_substring(string_1, string_2) << std::endl;

    return 0;
}