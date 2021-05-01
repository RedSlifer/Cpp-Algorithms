#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>

const int NUMBER_OF_BANKS = 5;

int main()
{
    std::vector<std::vector<std::string>> informations;
    std::vector<int> unsafes, memory;
    std::vector<std::string> row;
    std::array<std::array<std::string, NUMBER_OF_BANKS>, NUMBER_OF_BANKS> loans;
    std::array<float, NUMBER_OF_BANKS> balances;
    unsigned number_of_banks, i, j, k, max_column = 0;
    float limit, balance = 0.0;
    std::string string;

    std::cin >> limit;
    std::cin.ignore();
    
    for (i = 0; i < NUMBER_OF_BANKS; i++)
    {
        std::getline(std::cin, string);
        std::istringstream iss (string);
        while (iss >> string)
        {
            row.push_back(string);
        }
        informations.push_back(row);
        row.clear();
    }

    for (i = 0; i < NUMBER_OF_BANKS; i++)
    {
        if (informations[i].size() > max_column)
        {
            max_column = informations[i].size();
        }
    }
    
    for (i = 0; i < NUMBER_OF_BANKS; i++)
    {
        for (j = 0; j < NUMBER_OF_BANKS; j++)
        {
            loans[i][j] = "X";
        }
    }
    
   for (i = 0; i < NUMBER_OF_BANKS; i++)
   {
       for (j = 2; j < informations[i].size(); j += 2)
       {
            loans[i][std::stoi(informations[i][j])] = informations[i][j + 1];
       }
   }

   while (true)
   {
        for (i = 0; i < NUMBER_OF_BANKS; i++)
        {
            for (j = 0; j < NUMBER_OF_BANKS; j++)
            {
                if (loans[i][j] != "X")
                {
                    balance += std::stof(loans[i][j]);
                }
            }
            balances[i] = balance + std::stof(informations[i][0]);
            balance = 0.0;
        }

        for (i = 0; i < NUMBER_OF_BANKS; i++)
        {
            if (std::find(memory.begin(), memory.end(), i) != memory.end())
            {
                continue;
            }
            else
            {
                if (balances[i] < limit)
                {
                    unsafes.push_back(i);
                }
            }
        }

        for (i = 0; i < unsafes.size(); i++)
        {
            memory.push_back(unsafes[i]);
        }

        if (unsafes.size() > 0)
        {
            for (i = 0; i < unsafes.size(); i++)
            {
                for (j = 0; j < NUMBER_OF_BANKS; j++)
                {
                    for (k = 2; k < informations[j].size(); k += 2)
                    {
                        if (informations[j][k] == std::to_string(unsafes[i]))
                        {
                            loans[j][unsafes[i]] = "X";
                        }
                    }
                }
            }
            unsafes.clear();
        }
        else
        {
            break;
        }
   }
   
    std::cout << std::endl;
    std::cout << "Unsafe banks are ";

    for (i = 0; i < memory.size(); i++)
    {
        std::cout << memory[i] << " ";
    }

    return 0;
}