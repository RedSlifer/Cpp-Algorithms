#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A)
{
    size_t i;
    vector<int> control;

    if (A.size() == 0)
    {
        return 1;
    }
    else
    {
        sort(A.begin(), A.end());
        for (i = 1; i <= A.size() + 1; i++)
        {
            control.emplace_back(i);
        }
        for (i = 0; i < control.size(); i++)
        {
            if (!(find(A.begin(), A.end(), control[i]) != A.end()))
            {
                return control[i];
            }
        }
    }
}

int main()
{
    vector<int> A {2};
    cout << solution(A) << endl;
    return 0;
}