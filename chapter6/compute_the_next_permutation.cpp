/*****************************************************************************/
/* Task:    write a program that takes as input a permutation, and returns   */
/*          the next permutation under dictionary ordering. If the           */
/*          permutation is the last permutation, return the empty array.     */
/* Date:    2025-09-15                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int>    nextPermutation(std::vector<int> perm)
{
    int k{ static_cast<int>(perm.size()) - 2 };

    while (k >= 0 && perm[k] >= perm[k + 1])
        --k;
    if (k == -1)
        return {}; // perm is the last permutation.
    // Swap the smallest entry after index k that is greater than perm[k].
    // We exploit the fact that perm[k + 1 : perm.size() - 1] is decreasing
    // so if we search in the reverse order, the first entry that is greater
    // than perm[k] is the smallest such entry.
    std::swap(*std::find_if(perm.rbegin(), perm.rend(),
            [&](int a) { return a > perm[k]; }), perm[k]);
    // Since perm[k + 1 : perm.size() - 1] is in decreasing order, we can
    // build the smallest dictionary ordering of this subarray by reversing it.
    std::reverse(perm.begin() + k + 1, perm.end());
    return (perm);
}

int main()
{
    std::vector<int>    A{ 6, 2, 1, 5, 4, 3, 0 };
    std::vector<int>    result{ nextPermutation(A) };

    for (auto i : result)
        std::cout << i << " ";
    std::cout << std::endl;
    return (0);
}
