/**************************************************************************/
/* Task:    Write a program that takes two arrays representing integers   */
/*          and returns an array of integers representing their product   */
/* Date:    2025-09-08                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

// Time complexity: There are m partial products, each with at most
//                  O(nm)
std::vector<int>    multiply(std::vector<int>& arr1, std::vector<int>& arr2)
{
    bool    sign { arr1.front() * arr2.front() < 0 ? true : false };
    arr1.front() = std::abs(arr1.front());
    arr2.front() = std::abs(arr2.front());
    std::vector<int>    result(arr1.size() + arr2.size(), 0);
    
    // perform multiplication
    for (int  i { static_cast<int>(arr1.size() - 1) }; i >= 0; --i)
    {
        for (int  j { static_cast<int>(arr2.size() - 1) }; j >= 0; --j)
        {
            int product { arr1[i] * arr2[j] + result[i + j + 1]};
            result[i + j + 1] = product % 10;
            result[i + j] += product / 10;
        }
    }
    // remove leading zeros
    auto it { result.begin() };
    while (it != result.end() && !*it)
        ++it;
    result.erase(result.begin(), it);
    if (result.empty())
        return {0};
    // check for sign
    if (sign)
        result.front() *= -1;
    return (result);
}

int main()
{
    std::vector<int>    one { -7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7 };
    std::vector<int>    two { 1, 9, 3, 7, 0, 7, 7, 2, 1 };

    std::vector<int>    result { multiply(one, two) };
    for (auto i : result)
        std::cout << i;
    std::cout << std::endl;
    return (0);
}
