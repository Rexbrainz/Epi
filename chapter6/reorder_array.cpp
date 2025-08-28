/**************************************************************************/
/* Task:    Write a program that takes as input and array of integers and */
/*          reorders the array so that the even entries appear first.     */
/* Date:    2025-08-28                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

// My solution to the problem
// Time complexity: O(n).
void    reorder_array(int* arr, int size)
{
    if (size <= 1)
        return ;
    int*    even{ arr }, *odd{ arr + size - 1 }; 

    while (even < odd)
    {
        while (even != odd && *even % 2 == 0)
            ++even;
        while (odd != even && *odd % 2 != 0)
            --odd;
        if (even >= odd)
            return ;
        std::swap(*even, *odd);
        ++even;
        --odd;
    }
}

/* EPI's solution
    This approach appears very simple and straight forward.
    It avoids multiple loops and comparisons, but swaps more.
    It is simple to understand and follow.
    Time complexity: O(n).
*/
void    EvenOdd(std::vector<int>* A_ptr)
{
    std::vector<int>&    A{ *A_ptr };
    int next_even{ }, next_odd{ static_cast<int>(A.size() - 1) };
    
    while (next_even < next_odd)
    {
        if (A.at(next_even) % 2 == 0)
            ++next_even;
        else
            std::swap(A.at(next_even), A.at(next_odd--));
    }
}

int main()
{
    int arr[] { 3, 8, 5, 12, 7, 6 };
    std::vector<int> varr{ 3, 8, 5, 12, 7, 6 };

    reorder_array(arr, 6);
    for (int i{}; i < 6; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    EvenOdd(&varr);
    for (auto i : varr)
        std::cout << i << " ";
    std::cout << std::endl;
    return (0);
}
