/*****************************************************************************/
/* Task:    write a program which takes as input a sorted array and          */
/*          updates it so that a dupicates have been removed and the         */
/*          remaining elements have been shifted left to fill the emptied    */
/*          indices. Return the number of valid elements.                    */
/* Date:    2025-09-11                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

// Time complexity: O(n)
int deleteDuplicates(std::vector<int>* A_ptr)
{
  std::vector<int>& A { *A_ptr };
  int write_index_index { 1 };

  for (int i { 1 }; i < A.size() ; ++i)
  {
    if (A[write_index_index - 1] != A[i])
    {
      A[write_index_index] = A[i];
      ++write_index_index;
    }
  }
  return (write_index_index);
}

/*
 * Very instructive solution
 * We maintain a pointer to where we need to write_index (write_index_index)
 * we compare the element at write_index_index - 1 with the element at i.
 * This way if we find duplicates, we simply increment i while
 * write_index_index continues pointing to the index at where we will
 * enter a new value after processing the current duplicate.
 * Therefore, write_index_index will always be 1 index ahead of the
 * element we are checking (A[write_index_index - 1])
 */
   

// Second Variant
/*
 * Implement a function which takes as input an array and a key,
 * and updates the array so that all occurences of the input key have
 * been removed and the remaining elements have been shifted left to
 * fill the emptied indices. Return the number of remaining elements.
 * There are no requirements as to the values stored beyond the last 
 * valid elemnt.
 */

int removeKey(std::vector<int>* A_ptr, int key)
{
  std::vector<int>&  A { *A_ptr };
  int write_index_index {};

  for (int i{}; i < A.size(); ++i)
  {
    if (A[i] != key)
      A[write_index_index++] = A[i];
  }
  return (write_index_index);
}


// Third Variant
/*
 * write_index a prgoram which takes as input a sorted array A of integers
 * and a positive integer m, and updates A so that if x appears m times in
 * A, it appears exactly min(2, m) times in A. The update to A shoud be 
 * performed in one pass, and no additional storage maybe allocated.
 */

int AllowAtMostTwoDuplicates(std::vector<int>* A_ptr, int m)
{
  std::vector<int>& A { *A_ptr };
  int count{};
  int write_index {0};

  for (int i{}; i < A.size(); ++i)
  {
    if (i == 0 || A[i] != A[i - 1])
      count = 1;
    else
      ++count;
    if (count <= std::min(2, m)) 
      A[write_index++] = A[i];
  }
  return (write_index);
}

int main()
{
  std::vector<int> A {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2 , 3, 4, 4, 5, 5, 5, 5, 6, 6, 6,};

  int result { AllowAtMostTwoDuplicates(&A, 3) };
  for (int i{}; i < result; ++i)
    std::cout << A[i] << " ";
  std::cout << std::endl;
  return (0);
}

