/*****************************************************************************/
/* Task:    Implement string/integer inter-conversion functions.             */
/* Date:    2025-09-22                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <exception>

int stringToInt(const std::string& s)
{
    int i{};
    int sign{ 1 };
    int number{};

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(i < s.length())
    {
        number = number * 10 + s[i] - '0';
        i++;
    }
    return (number * sign);
}

std::string intToString(int num)
{
    std::string s;
    if (num < 0)
    {
        s = '-';
        num = -num;
    }
    int length = std::floor(log10(num)) + 1;
    int power = std::pow(10, length - 1);

    while(num)
    {
        char c = num / power + '0';
        s += c;
        num %= power;
        power /= 10;
    }
    return (s);
}
/*
* Another idea, to avoid using floor and pow functions, would
* be to compute intToString from the last value to the first
* if the value is negative, we append - afterwards we return
* a reverse of the string
*/

int main()
{
    std::string s("-123");
    int digit{ -1024 };
    
    std::string s_result { intToString(digit) };
    int result { stringToInt(s) };
    std::cout << "String to int: " << result << std::endl;
    std::cout << "Int to string: " << s_result << std::endl;
    return (0);
}
