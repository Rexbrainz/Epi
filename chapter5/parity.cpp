/**************************************************************************/
/* Task:     Compute the parity of a word                                 */
/* Date:     2025-08-11                                                   */
/* Author:   Success Daniel                                               */
/* ************************************************************************/

#include <iostream>

using namespace std;

/*
  Parity of a binary word is 1 if the number of set bits
  in the word is odd otherwise 0 when even.
*/


// O(n): every bit is tested if all bits in x are set.
short   brute_force_parity(unsigned long x)
{
    short   result { };
    while (x)
    {
        // result is always toggled to 0 or 1
        result ^= x & 1;
        x >>= 1;
    }
    return (result);
}

// O(k): Only set bits are tested.
short   brian_kernighan_parity(unsigned long x)
{
    short   result { };
    while (x)
    {
        result ^= 1;
        // Unsets the last set bit
        x &= (x - 1);
    }
    return (result);
}

/*
    Uses a lookup table (array), where the values in the array
    are the parity values of each index from 0 to 15.
    This method, splits the word x into nibbles of 4bits.
    The idea is that the binary of 0 to 15 fits into 4 bits, so
    instead of testing the bits, or going after them using Brian's
    algorithm, we could simple go through the word x 4 bits at a time.
    O(n / L), where L is the nibble size.
*/
short   nibble_parity(unsigned long x)
{
    short   result { };
    const int lookup[16] { 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0 };

    while (x)
    {
        result ^= lookup[x & 0xF];
        x >>= 4;
    }
    return (result);
}

/*
    Uses xor to update the word x, shifting x by a shift value
    which starts at sizeof word / 2 and updated each time
    through out the loop dividing by 2.
    When the loop ends, the current value of x & 1 returns the
    parity of the original value x.
    Note: The shift_value tells us how many bits in x that is
    still relevant for computing parity, since the last shift value
    is 1, we use the & operator to extract the parity of x.
    O(log n)
*/

short   xor_fold_parity(unsigned long x)
{
    size_t  num_bits { sizeof(x) * 8 };
    size_t   shift_value { num_bits / 2 };

    while (shift_value)
    {
        x ^= x >> shift_value;
        shift_value /= 2;
    }
    return (x & 1);
}

int main()
{
    int brute_result { brute_force_parity(42) };
    int b_k_result { brian_kernighan_parity(42) };
    int nibble_result { nibble_parity(42) };
    int xor_fold_result { xor_fold_parity(42) };

    cout << "Brute force parity result: " << brute_result << endl;
    cout << "Brian kernighan parity result: " << b_k_result << endl;
    cout << "Nibble parity result: " << nibble_result << endl;
    cout << "xor_fold parity result: " << xor_fold_result << endl;
    return (0);
}

