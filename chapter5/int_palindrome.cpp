
/***************************************************************************/
/* Task:     Write a program that takes an integer and determines if that  */
/*           integer's representation as a decimal string is a palindrome. */
/*           i.e the integer is same going forward and backward.           */
/* Date:     2025-08-22                                                    */
/* Author:   Success Daniel                                                */
/* *************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

// The first idea i came up with and my implementation
bool    is_int_palindrome(int x)
{
    long    power { 1 };

    if (x < 0)
        return (false);
    for (int temp { x }; temp > 9; temp /= 10)
        power *= 10;
    while (x)
    {
        int current_last { x % 10 };
        int current_first { static_cast<int>(x / power) };
        if (current_last != current_first)
            return (false);
        x /= 10;
        power /= 10;
        if (x != 0 && power != 0)
        {
            x %= power;
            power /= 10;
        }
    }
    return (true);
}

// Epi approach
bool    is_palindrome_number(int x)
{
    if (x < 0)
        return (false);
    // Get the length of x
    int digit_length { static_cast<int>(floor(log10(x)) + 1) };
    // Use the length of x to get multiples of 10 that can divide x
    // to give us the first digit in x
    int power_of_ten { static_cast<int>(pow(10, digit_length - 1)) };
    for (int i { }; i < (digit_length / 2); ++i)
    {
        if (x / power_of_ten != x % 10)
            return (false);
        x /= power_of_ten; // Remove the most significant digit of x
        x /= 10; // Remove the least significant digit of x
        power_of_ten /= 100;
    }
    return (true);
}

int main()
{
    int x;

    cout << "Enter integer to check: ";
    cin >> x;
    bool    result { is_int_palindrome(x) };
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return (0);
}
