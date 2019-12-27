#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string find_all_occurences(int a, int b)
{
    int i;
    size_t pos;
    std::string string_a = std::to_string(a);
    std::string string_b = std::to_string(b);
    std::string string_c;
    std::string ouput;
    std::vector<size_t> indexes;

    pos = string_b.find(string_a);
    if (pos != std::string::npos)
    {
        while(pos != std::string::npos)
        {
            indexes.push_back(pos);
            pos = string_b.find(string_a, pos + string_a.size());
        }
        for (i  = 0; i < indexes.size(); i++)
        {
            string_c.append(std::to_string(indexes[i]));
        }
        ouput = string_c;
    }
    else
    {
        ouput = "-1";
    }
    return ouput;
}

int main()
{
    int a, b;

    std::cin >> a >> b;

    std::cout << find_all_occurences(a, b) << std::endl;
    return 0;
}