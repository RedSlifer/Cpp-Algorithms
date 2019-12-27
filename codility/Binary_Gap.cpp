#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>

int solution(int N)
{
    size_t element, i;
    int binary_value, result;
    char binary_char;
    std::string binary_number = "";
    std::vector<int> ones;
    std::vector<int> gaps;

    while (N != 0)
    {
        binary_value = N % 2;  //Decimal to binary
        binary_char = static_cast<char>(binary_value + '0');    //Get binary char,
        binary_number = binary_char + binary_number;    //Add to binary string
        N = N / 2;
    }
  
    element = binary_number.find("0");  //Find the index of the first zero
    if (element == 4294967295)  //If not zeros exists the function find returns the value 4294967295
    {
        return 0;
    }
    else
    {
        element = binary_number.find("1");  //Find the index of the first one
        ones.emplace_back(element); //Add the index of the first one
        for (i = element + 1; i < binary_number.size(); i++)
        {
            if (binary_number[i] == '1')
            {
                ones.emplace_back(i);   //Add the index of the others zeros
            }
        }
    }
    
    for (i = 0; i < ones.size() - 1; i++)
    {
        gaps.emplace_back(std::abs(ones[i] - ones[i + 1])); //Add the values of the gaps
    }
    
    if (ones.size() > 1)
    {
        return *std::max_element(gaps.begin(), gaps.end()) - 1; //Return the maximum gap
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N;
    std::cin >> N;

    std::cout << solution(N) << std::endl;
    return 0;
}