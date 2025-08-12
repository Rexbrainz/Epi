/***************************************************************************/
/* Task:     Implement code that takes as input a 64 bit integer and swaps */
/*           the bits at indices i and j.                                  */
/* Date:     2025-08-12                                                    */
/* Author:   Success Daniel                                                */
/* *************************************************************************/

#include <iostream>

using namespace std;

// Time complexity: O(1), independent on number of bits of word.
long  swap_bits(long word, int i, int j)
{
    long bit_i { };
    long bit_j { };
    long mask { 1 };

    //extract the bits
    bit_i |= (word >> i) & 1;
    bit_j |= (word >> j) & 1;
    
    if (bit_i != bit_j)
    {
        //since the bits at i and j are not same
        //simply toggle them using a mask with 1s
        //at position i and j.
        word ^= mask << i; 
        word ^= mask << j; 
    }
    return (word);
}
/*
    What I learned:
        My main issue in solving this problem, was making the swap.
        I fixated a lot on using the | or ^ operators with the
        extracted bits, but that would not change a set bit.
        I thought about clearing that bit, after extraction, so using
        the | operator would be easy to insert bit_j into position i
        and same for bit_i, but that did not work, because, applying 0 
        on word, using & simply zeros word out.
        This went on, until i understood, that i needed the extracted
        bits only to make sure if they are same or not, and that i do
        not need to swap but toggle the bits at the correct positions.
*/

int main()
{
    long word { 42 };

    long result { swap_bits(word, 2, 5) };
    cout << "word: " << word << endl << "result: " << result << endl;
    return (0);
}
