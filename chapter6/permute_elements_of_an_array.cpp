/*****************************************************************************/
/* Task:    write a program that takes and array of n elements and a         */
/*          permutation P, apply P to A.                                     */
/* Date:    2025-09-15                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>


void    applyPermutation(std::vector<int>* perm_ptr, std::vector<int>* A_ptr)
{
    std::vector<int>&   perm { *perm_ptr };
    std::vector<int>&   A { *A_ptr };

    for (int i{}; i < A.size(); ++i)
    {
        int next { i };
        while (perm[next] >= 0)
        {
            std::swap(A[i], A[perm[next]]);
            int temp { perm[next] };
            // Subtracts perm.size() from an entry in perm to make it 
            // negative. which indicates the corresponding move has been 
            // performed.
            perm[next] -= perm.size();
            next = temp;
        }
    }// Restore perm.
    for_each(std::begin(perm), std::end(perm),
        [&perm](int& x) { x += perm.size(); });

}

int main()
{
    std::vector<int>    a { 34, 0, 20, 50 };
    std::vector<int>    perm { 2, 0, 1, 3 };

    applyPermutation(&perm, &a);
    for (auto i : a)
        std::cout << i << " ";
    std::cout << std::endl;
    return (0);
}
