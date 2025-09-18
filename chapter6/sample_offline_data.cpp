/*****************************************************************************/
/* Task:    Implement and algorithm that takes as input an array of distinct */
/*          elements and a size, and returns a subset of the given size of   */
/*          the array elements. All subsets should be equally likey. Return  */
/*          the result in input array itself.                                */
/* Date:    2025-09-18                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Time complexity: O(k)
// Space complexity O(1).
void    randomSampling(int k, std::vector<int>* A_ptr)
{
    std::vector<int>&   A{ *A_ptr };
    std::random_device  rd;
    std::default_random_engine  gen(rd()); // engine

    for (int i{}; i < k; ++i)
    {
        // generate random index from i to size - 1.
        std::uniform_int_distribution<int> dist(i, A.size() - 1);
        // dist now holds those indices, dist(gen) returns us just one 
        // of those indices.
        int r{ dist(gen) };
        std::swap(A[i], A[r]);
    }
}

int main()
{
    std::vector<int>    A{3, 7, 5, 11, 13};
    randomSampling(3, &A);

    for (int i{}; i < 3; ++i)
        std::cout << A[i] << " ";
    std::cout << std::endl;
    return (0);
}
