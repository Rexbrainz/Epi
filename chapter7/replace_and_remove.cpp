
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

int main()
{
  char s[]{ 'a', 'c', 'b', 'a', 'b', 'a', 'b' };
  int size { replaceAndRemove(7, s) };
  
  for (int i{}; i < size; ++i)
    std::cout << s[i] << " ";
  std::cout << std::endl;
  return (0);
}
