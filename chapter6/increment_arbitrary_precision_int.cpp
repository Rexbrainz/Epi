/**************************************************************************/
/* Task:    Write a program which takes as input an array of digits       */
/*          encoding a decimal number D and updates the array to represent*/
/*          the number D + 1.                                             */
/* Date:    2025-09-01                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

// My naive approach
void    increment_array(std::vector<int>& digits)
{
    if (digits.size() < 1)
        return ;

    long    number{};
    for (auto digit : digits)
        number = number * 10 + digit;
    ++number;
    int num_length = floor(log10(number)) + 1;
    int power = pow(10, num_length - 1);
    for (auto& digit : digits)
    {
        digit = number / power;
        number %= power;
        power /= 10;
    }
    if (num_length > digits.size())
        digits.push_back(number);
}

// Fast Epi approach
// Time complexity: O(n).
void    PlusOne(std::vector<int>& A)
{
    ++A.back();
    for (auto i { A.size() - 1 }; i > 0 && A[i] == 10; --i)
    {
        A[i] = 0;
        A[i - 1]++;
    }
    if (A[0] == 10)
    {
        A[0] = 0;
        A.insert(A.begin(), 1);
    }
}

int main()
{
    std::vector<int> digits{ 9, 9, 9 };
    PlusOne(digits);
    for (auto digit : digits)
        std::cout << digit << " ";
    std::cout << std::endl;
    return (0);
}
