/***************************************************************************/
/* Task:     Write a program which takes an integer and returns the        */
/*           integer corresponding to the digits of the input written in   */
/*           reverse order. For example, the reverse of 42 is 24, and the  */
/*           reverse of -314 is -413.                                      */
/* Date:     2025-08-21                                                    */
/* Author:   Success Daniel                                                */
/* *************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int reverse_digit(int x)
{
    int result { };
    int x_abs{ abs(x) };

    while (x_abs)
    {
        result = result * 10 + x_abs % 10;
        x_abs /= 10;
    }
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
