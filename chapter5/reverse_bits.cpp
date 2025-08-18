/*****************************************************************************/
/* Task:     Write a program that takes a 64-bit word and returns the 64-bit */
/*           word consisting of the bits of the input word in reverse order. */
/* Date:     2025-08-12                                                      */
/* Author:   Success Daniel                                                  */
/* ***************************************************************************/

#include <iostream>

using namespace std;

//Time complexity:  O(n)
long    brute_force_reverse_bits(long word)
{
    long    result { };
    short   i { 0 };
    int     num_bits { sizeof(word) * 8 };

    while (i < num_bits)
    {
        result <<= 1;
        result |= word >> i & 1;
        ++i;
    }
    return (result);
}
//Other approaches: i. Looping num_bits / 2 times, and using the
//                  swap bit function which takes the word to swap
//                  and the positions to swap.
//                  ii. Using a lookup table[256] with reversed values 
//                  for each possible byte. Time complexity is O(1)

/*
    long    Reverse_bits_lookup_table(long x)
    {
        const int   k_word_size = 16;
        const int   k_bit_mask = 0xFFFF;
        return precomputed_reverse[x & k_bit_mask] << (3 * k_word_size) |
           precomputed_reverse[(x >> k_word_size) & k_bit_mask]
                                                << (2 * k_word_size) |
            precomputed_reverse[(x >> (2 * k_word_size)) & k_bit_mask]
                                                 << k_word_size |
            precomputed_reverse[(x >> (3 * k_word_size)) & k_bit_mask];
    }
*/
