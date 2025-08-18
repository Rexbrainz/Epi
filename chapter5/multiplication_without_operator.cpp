/****************************************************************************/
/* Task:     Write a program that multiplies two nonnegative integers       */
/*           without arithmetical operators.                                */
/*           same weight as x and their difference, y - x is as small as    */
/*           possible. You can assume x is not 0 or all 1s.                 */
/*           Weight here means that x and y has the same number of set bits */
/* Date:     2025-08-18                                                     */
/* Author:   Success Daniel                                                 */
/* **************************************************************************/

#include <iostream>

using namespace std;

unsigned    add(unsigned a, unsigned b)
{
    unsigned sum { }, carrying { }, k { 1 }, temp_a { a }, temp_b { b };

    while (temp_a || temp_b)
    {
        unsigned    ak { a & k };
        unsigned    bk { b & k };
        unsigned    carryout { (ak & bk) | (ak & carrying) 
                        | (bk & carrying) };
        sum |= (ak ^ bk ^ carrying);
        carrying = carryout << 1;
        k <<= 1;
        temp_a >>= 1;
        temp_b >>= 1;
    }
    return (sum | carrying);
}
unsigned    multiply(unsigned x, unsigned y)
{
    unsigned    sum { };
    while (x)
    {
        if (x & 1)
            sum = add(sum, y);
        x >>= 1;
        y <<= 1;
    }
    return (sum);
}

int main()
{
    unsigned    x { 2 }, y { 3 };
    cout << x << " times " << y << ": " << multiply(x, y) << endl;
    return (0);
}
