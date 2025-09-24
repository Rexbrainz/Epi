
/*****************************************************************************/
/* Task:    Write a program which takes as input an array of characters,     */
/*          and removes each 'b' and replaces each 'a' by two 'd's.          */
/*          Specifically, along with the array size as int which denotes     */
/*          the number of entries of the array that the operation is applied */
/*          to. You do not have to worry about subsequent entries.           */
/* Date:    2025-09-24                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

/*
 * Time complexity: O(n)
 */
int replaceAndRemove(int size, char s[])
{
  // Forward iteration: remove "b"s and count the number of "a"s
  int write_idx{}, count{};

  for (int i{}; i < size; ++i)
  {
    if (s[i] != 'b')
      s[write_idx++] = s[i];
    if (s[i] == 'a')
      ++count;
  }

  // Backward iteration: replace "a"s with "dd"s starting from the end.
  int cur_idx{ write_idx - 1 };
  write_idx = write_idx + count - 1;
  const int final_size{ write_idx + 1 };
  while (cur_idx >= 0)
  {
    if (s[cur_idx] == 'a')
    {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    }
    else
    {
      s[write_idx--] = s[cur_idx];
    }
    --cur_idx;
  }
  return (final_size);
}

/*
 * The second variant, with telex encoding is solved similar to 
 * the solution above, first get the length of A and for
 * each punctuation add in the length of the A for the first pass.
 * For the second pass we start from the back of A maintaining a 
 * write and a read pointer. The read pointer starts from the
 * last char in A while write index starts from total length of 
 * A with the punctuation - 1. so while read pointer is greater 
 * than or equal to zero, we copy read into write, and the 
 * punctuation backwards.
 * Third variant:
 * Merge two sorted arrays, assuming A has enough size to hold both arrays.
 */

void  mergeTwoSortedArrays(std::vector<int>& A, int m,
    const std::vector<int>& B, int n)
{
  int i{m - 1}, j{n - 1}, k{m + n + 1};

  while (j >= 0)
  {
    if (i >= 0 && A[i] > B[j])
    {
      A[k] = A[i];
      --i;
    }
    else 
    {
      A[k] = B[j];
      --j;
    }
    --k;
  }
}

int main()
{
  //char s[]{ 'a', 'c', 'b', 'a', 'b', 'a', 'b' };
  //int size { replaceAndRemove(7, s) };
  
  std::vector<int> A;
  A.reserve(6);
  A[0] = 1, A[1] = 3, A[2] = 5;
  std::vector<int> B{2, 4, 6};
  mergeTwoSortedArrays(A, 3, B, 3);
  for (size_t i{}; i < A.capacity(); ++i)
    std::cout << A[i] << " ";
  std::cout << std::endl;
  return (0);
}
