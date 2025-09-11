/*****************************************************************************/
/* Task:    Write a program which takes as input a sorted array and updates  */
/*          it so that a dupicates have been removed and the remaining       */
/*          elements have been shifted left to fill the emptied indicies     */
/*          Return the number of valid elements.                             */
/* Date:    2025-09-11                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <vector>

// Time complexity: O(n)
int deleteDuplicates(std::vector<int>* A_ptr)
{
  std::vector<int>& A { *A_ptr };
  int write_index { 1 };

  for (int i { 1 }; i < A.size() ; ++i)
  {
    if (A[write_index - 1] != A[i])
    {
      A[write_index] = A[i];
      ++write_index;
    }
  }
  return (write_index);
}

/*
 * Very instructive solution
 * We maintain a pointer to where we need to write (write_index)
 * we compare the element at write_index - 1 with the element at i.
 * This way if we find duplicates, we simply increment i while
 * write_index continues pointing to the index at where we will
 * enter a new value after processing the current duplicate.
 * Therefore, write_index will always be 1 index ahead of the
 * element we are checking (A[write_index - 1])
 */
   

int main()
{
  std::vector<int> A {1, 2, 3, 3, 4, 5, 5};

  int result { deleteDuplicates(&A) };
  for (int i{}; i < result; ++i)
    std::cout << A[i] << " ";
  std::cout << std::endl;
  return (0);
}

