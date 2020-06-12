#include <iostream>

void selection_sort(std::string& string, unsigned high);
void selection_sort(std::string& string);

int main()
{
    std::string string;
    std::cout << "Enter a string: ";
    std::getline(std::cin, string);

    selection_sort(string);

    std::cout << "The sorted string is " << string << std::endl;
    return 0;
}

void selection_sort(std::string& string, unsigned high)
{
    int index_of_maximum, i;
    char maximum_element;

    //Find the largest element and its index
    if (high > 0)
    {
        index_of_maximum = 0;
        maximum_element = string[0];

        for (i = 1; i <= high; i++)
        {
            if (string[i] > maximum_element)
            {
                maximum_element = string[i];
                index_of_maximum = i;
            }
        }
        //Swap the largest with the last element in the list
        string[index_of_maximum] = string[high];
        string[high] = maximum_element;
        // Sort the remaining list
        selection_sort(string, high - 1);
    }
}

void selection_sort(std::string& string)
{
    selection_sort(string, string.size() - 1);
}
