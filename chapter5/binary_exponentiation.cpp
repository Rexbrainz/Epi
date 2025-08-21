/***************************************************************************/
/* Task:     Write a program that takes a double x and an integer y and    */
/*           returns x to the power y.You can ingnore over and under flows.*/
/* Date:     2025-08-21                                                    */
/* Author:   Success Daniel                                                */
/* *************************************************************************/

#include <iostream>

using namespace std;

/*
    Also known as binary exponentiation, allows you to compute
    x to the power of y, by doing more computation from every iteration
    for example, 3 to the power of 5 is 3 * 3 * 3 * 3 * 3, which takes
    more time O(y), howerver with the binary exponentiation method, you have
    3 * (9) * (9), this allows us run the loop for 3 times instead of 5 times.
    Note: if x were an int, it is better to use a long or long long
    to avoid overflow when squaring.
    Time Complexity: O(log y).
*/
double  power(double x, int y)
{
    double      result { 1.0 };
    long long   power { y };

    if (y < 0)
    {
        power = -power;
        x = 1.0 / x;
    }
    while (power)
    {
        if (power & 1) // similar to if (power % 2 == 1)
            result *= x; // 
        x *= x; // squaring
        power >>= 1; // similar to power /= 2;
    }
    return (result);
}

int main()
{

    cout << "2 to the power of 3: " << power(2, 3) << endl;
    return (0);
}
