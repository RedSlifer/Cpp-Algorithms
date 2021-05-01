#include <iostream>
#include <vector>

std::vector<unsigned> slice_list(std::vector<unsigned> list, unsigned start_position, unsigned final_position);
void list_printer(const std::vector<unsigned>& list);

int main()
{
    std::vector<unsigned> list {1, 4, 5, 6, 3, 5, 10};

    list_printer(slice_list(list, 0, 5));

    return 0;
}

std::vector<unsigned> slice_list(std::vector<unsigned> list, unsigned start_position, unsigned final_position)
{
    std::vector<unsigned> sliced_list;

    std::copy(list.begin() + start_position, list.end() - (list.size() - final_position), std::back_inserter(sliced_list));

    return sliced_list;
}

void list_printer(const std::vector<unsigned>& list)
{
    for (auto& i : list)
    {
        std::cout << i << " ";
    }
}
