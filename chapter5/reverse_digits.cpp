/***************************************************************************/
/* Task:     Write a program which takes an integer and returns the        */
/*           integer corresponding to the digits of the input written in   */
/*           reverse order. For example, the reverse of 42 is 24, and the  */
/*           reverse of -314 is -413.                                      */
/* Date:     2025-08-22                                                    */
/* Author:   Success Daniel                                                */
/* *************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int reverse_digit(int x)
{
    int result { };
    int x_abs{ abs(x) }; // Remove the negative sign if there is one.

    while (x_abs)
    {
        result = result * 10 + x_abs % 10;
        x_abs /= 10;
    }
    // if x is negative, return result as negative.
    return (x < 0 ? -result : result);
}

int main()
{
    int x;

    cout << "Enter digit to reverse: ";
    cin >> x;
    int result { reverse_digit(x) };
    cout << "Reverse of " << x << ": " << result << endl;
    return (0);
}
