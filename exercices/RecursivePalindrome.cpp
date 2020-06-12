#include <iostream>

bool recursive_palindrome(const std::string& string);

int main()
{
    std::string string;

    std::getline(std::cin, string);
    
	if (recursive_palindrome(string))
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    return 0;
}

bool recursive_palindrome(const std::string& string)
{
    if (string.size() <= 1) //Base case
    {
        return true;
    }
    else if (string[0] != string[string.size() - 1]) //Base case
    {
        return false;
    }
    else
    {
        return recursive_palindrome(string.substr(1, string.size() - 2));
    }
}
