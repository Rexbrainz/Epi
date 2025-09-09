/**************************************************************************/
/* Task:    Write a program which takes an array of n integers, where A[i]*/
/*          denotes the maximum you can advance from index i, and returns */
/*          if it is possible to advance to the last index starting from  */
/*          the beginning of the array.
/* Date:    2025-09-09                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>
#include <vector>

// Time Complexity: O(n)
bool    canAdvance(const std::vector<int>& nums)
{
    int max_reach{};
    int last_index{ static_cast<int>(nums.size() - 1) };
    
    for (int i{}; i <= max_reach && max_reach < last_index; ++i)
        max_reach = std::max(max_reach, nums[i] + i);
    return (max_reach >= last_index);
}
/*
 * What i learned:
 *  Instead of checking all possibilities, we needed a method,
 *  to allow us keep track of the max_steps we could take at
 *  each given index, this allows us to compute the max_reach 
 *  for every value in the array while we could still advance.
 *  We stop advancing when the index we are currently evaluating
 *  is bigger than max_reach. 
 *  Think of it like, you arrived at an index in the array, 
 *  (Note: not the value stored in the index, just the value of the
 *  index itself) and the value of the index is bigger than your
 *  max reach, this tells us that we could not have arrived here
 *  in any way, since we were keeping track of the highest max reach
 *  at all times.
 *  Therefore, if at the end of the loop max_reach is bigger than
 *  or equal to the array size - 1 (last index), then true is returned,
 *  else false.
 */

/*  Variant:    Write a program to compute the minimum number of
                steps needed to advance to the end of the array.
*/
// Time Complexity: O(n)
int minStepsToAdvance(const std::vector<int>& nums)
{
    int max_reach{};
    int last_index{ static_cast<int>(nums.size() - 1) };
    int current_end{};
    int jumps{};

    for (int i{}; i <= max_reach && current_end < last_index; ++i)
    {
        max_reach = std::max(max_reach, i + nums[i]);
        if (i == current_end)
        {
            ++jumps;
            current_end = max_reach;
        }
    }
    if (max_reach < last_index)
        return (-1);
    return (jumps);
}
/*
* What i learned from the variant:
*   Since we know how we can advance, we simply needed a way to track
*   how least number of times we could do that.
*   This is where jumps and current_end(which is the keeps track of 
    a max_reach value until we go beyond it). Whenever the current
    index we are processing equals current_end, we need a jump and we
    need to update current_end to be the now max_reach.
    So the number of jumps we get equals the min number of times
    we can advance to the end of the array.
    current_end is there to help us keep track of a particular max_reach,
    this tells us the max step we could advance at a particular time,
    so until you exhaust that max, do not update jump.
*/

int main()
{
    std::vector<int>    A{3, 3, 1, 0, 2, 0, 1};
    
    bool    result { canAdvance(A) };
    if (result)
        std::cout << "True, we can advance." << std::endl;
    else
        std::cout << "False, we cannot advance." << std::endl;
    return (0);
}
