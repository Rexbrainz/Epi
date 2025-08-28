/**************************************************************************/
/* Task:    Write a program that takes an array A and an index i into A,  */
/*          and rearranges the elements such that all elements less than  */
/*          A[i] (the pivot) appear first, followed by elements equal to  */
/*          the pivot, followed by elements greater than the pivot.
/* Date:    2025-08-28                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

// Time complexity O(n to the power 2)
// Space complexity O(1).
void    DutchFlagPartition(std::vector<int>* A_ptr, int p_index)
{
    if (p_index < 0 || p_index >=A_ptr->size())
        return ;
    std::vector<int>&    A{ *A_ptr };
    int pivot{ A_ptr->at(p_index) };
    // First pass: group elements larger than pivot.
    for (int i{}; i < A.size(); ++i)
    {
        // Look for a smaller element.
    for (int j { i + 1 }; j < A.size(); ++j)
        {
            if (A.at(j) < pivot)
            {
                std::swap(A.at(i), A.at(j));
                break ;
            }
        }
    }
    // Second pass: group elements larger than pivot
    for (int i{ static_cast<int>(A.size() - 1) }; i >= 0 && A.at(i) >= pivot; --i)
    {
        // Look for a larger element. Stop when we reach an element less
        // than pivot, since first pass has moved them to the start of A.
        for (int j{ i - 1 }; j >= 0 && A.at(j) >= pivot; --j)
        {
            if (A.at(j) > pivot)
            {
                std::swap(A.at(i), A.at(j));
                break ;
            }
        }
    }
}

// Time complexity: O(n)
// Space complexity: O(1).
void    DutchFlagPartition_two_loops(std::vector<int>* A_ptr, int p_index)
{
    std::vector<int>&   A { *A_ptr };
    int pivot { A.at(p_index) };
    // First pass: group elements smaller than pivot.
    int smaller = 0;
    for (int i {}; i < A.size(); ++i)
        if (A.at(i) < pivot)
            std::swap(A.at(i), A.at(smaller++));
    // Second pass: group elements larger than pivot.
    int larger { static_cast<int>(A.size() - 1) };
    for (int i { static_cast<int>(A.size() - 1) }; i >= 0 && A.at(i) >= pivot; --i)
        if (A.at(i) > pivot)
            std::swap(A.at(i), A.at(larger--));
}

//Trickier approach
//Similar to the above, however it approaches the problem
//by partitioning elements into less than, equal to and greater than.
void    Dfp_one_loop(std::vector<int>* A_ptr, int p_index)
{
    std::vector<int>&   A{ *A_ptr };
    int pivot{ A.at(p_index) };
    int smaller{}, equal{}, larger{ static_cast<int>(A.size()) };
    //keep iterating as long as there is an element we have not
    //checked against the pivot.
    while (equal < larger)
    {
        if (A.at(equal) < pivot)
            std::swap(A.at(smaller++), A.at(equal++));
        else if (A.at(equal) == pivot)
            ++equal;
        else
            std::swap(A.at(equal), A.at(--larger));
    }
}

int main()
{
    std::vector<int>    A { 7, 3, 9, 2, 8, 5, 6, 10, 4 };

    DutchFlagPartition_two_loops(&A, 4);
    for (auto i : A)
        std::cout << i << " ";
    std::cout << std::endl;
    return (0);
}

