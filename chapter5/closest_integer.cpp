/****************************************************************************/
/* Task:     Write a program which takes as input a nonnegative integer x   */
/*           and returns a number y which is not equal to x, but has the    */
/*           same weight as x and their difference, y - x is as small as    */
/*           possible. You can assume x is not 0 or all 1s.                 */
/*           Weight here means that x and y has the same number of set bits */
/* Date:     2025-08-18                                                     */
/* Author:   Success Daniel                                                 */
/* **************************************************************************/

#include <iostream>

using namespace std;

// bruteforce solution and very inefficient
unsigned int    num_of_set_bits(unsigned long x)
{
    unsigned int    count { };

    while (x)
    {
        x &= (x - 1);
        ++count;
    }
    return (count);
}

unsigned long    closest_weight(unsigned long x)
{
    unsigned long   y { x };
    unsigned long   z { x };
    bool            y_or_z { false };
    unsigned int    x_weight { num_of_set_bits(x) };

    while (true)
    {
        --y;
        if (num_of_set_bits(y) == x_weight)
            break ;
        ++z;
        if (num_of_set_bits(z) == x_weight)
        {
            y_or_z = true;
            break ;
        }
    }
    if (y_or_z)
        return (z);
    return (y);
}

/*
  Better approach: All we care about is to flip two rightmost 
                 consecutive bits that ain't the same.
  Time complexity : O(n)
*/
unsigned long    nearest_weighted_integer(unsigned long x)
{
    // Number of bits in an unsigned long
    const int   num_of_bits = 64;

    for (int i { }; i < num_of_bits - 1; ++i)
    {
        if (((x >> i) & 1) != ((x >> (i + 1)) & 1))
        {
            // Swap first 2 dissimilar bits
            x ^= 1UL << i | 1UL << (i + 1);
            return (x);
        }
    }
    // Throw error if all bits of x are 0 or 1.
    throw invalid_argument("All bits are 0 or 1");
}

/*
* Best Approach: Similar to the approach directl above
* Time complexity: O(1)
*/

unsigned long    closest_to_weight(unsigned long n)
{
    if (n <= 0 || n == numeric_limits<unsigned long>::max())
        throw invalid_argument("All bits are 0 or 1");

    unsigned long   neg { ~n };
    //isolate the lowest set bit
    unsigned long   rightmost_set_bit { n & ~(n - 1) };
    //isolate the lowest non set bit
    unsigned long   rightmost_non_set_bit { neg & ~(neg - 1 ) };

    //We compare to know the lowest non set bit is located.
    //if it is greater then n has all 1s before this 0.
    if (rightmost_non_set_bit > rightmost_set_bit)
    {
        //We add to n here because the swapped bits will result
        //to a value bigger than n, since the position of the
        //lowest 0 is higher than that of the 1 in n
        return (n + (rightmost_non_set_bit - 
            (rightmost_non_set_bit >> 1)));
    }
    //here we subtract because the lowest set bit will be swapped 
    //with a less significant non set bit. which definitely results
    //to a value less than n.
    return (n - (rightmost_set_bit - (rightmost_set_bit >> 1)));
}

int main()
{
    unsigned long    x { 7 };
    unsigned long    y { closest_to_weight(x) };

    cout << "Closest weight of " << x << ": " << y << endl;
    return (0);
}
