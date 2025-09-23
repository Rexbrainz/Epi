/*****************************************************************************/
/* Task:    Write a program that performs base conversion. The input is a    */
/*          string, an integer b1, and another integer b2, The string        */
/*          represents an integer in base b1.                                */
/* Date:    2025-09-22                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <exception>

int toBaseTen(const std::string& digit, int base)
{
    int size { static_cast<int>(digit.length()) - 1 };
    int result{0};

    for (auto c : digit)
    {
        int val;
        if (c >= '0' && c <= '9')
            val = c - '0';
        else if (c >= 'A' && c <= 'F')
            val = c - 'A' + 10;
        else
            throw std::invalid_argument("Invalid character");
        result = result * base + val;
    }
    return (result);
}

std::string baseToBase(const std::string& s, int b1, int b2)
{
    bool        sign{false};
    std::string result;
    int         base_ten;

    if (s[0] == '-')
        sign = true;
    if (sign)
        base_ten = toBaseTen(s.substr(1), b1);
    else
        base_ten = toBaseTen(s, b1);
    if (base_ten == 0)
        return ("0");
    while (base_ten)
    {
        int rem { base_ten % b2 };
        char c;
        if (rem < 10)
            c = '0' + rem;
        else
            c = 'A' + rem - 10;
        result += c;
        base_ten /= b2;
    }
    if (sign)
        result += '-';
    return {result.rbegin(), result.rend()};
}

/*
* EPI method that i did not understand, based on the recursive
* construct from base approach.
*/
std::string constructFromBase(int num_as_int, int base)
{
    return (num_as_int == 0 ? "" : 
                constructFromBase(num_as_int / base, base) + 
                    (char)(num_as_int % base >= 10 ? 'A' + num_as_int % base - 10 :
                            '0' + num_as_int % base));
}

std::string convertBase(const std::string& num_as_string, int b1, int b2)
{
    bool    is_negative{ num_as_string.front() == '-' };
    int     num_as_int{};

    for (size_t i = (is_negative == true ? 1 : 0);
        i < num_as_string.size(); ++i)
    {
        num_as_int *= b1;
        num_as_int += isdigit(num_as_string[i]) ? num_as_string[i] - '0'
                        : num_as_string[i] - 'A' + 10;
    }
    return ((is_negative ? "-" : "") +
            (num_as_int == 0 ? "0" : constructFromBase(num_as_int, b2)));
}
int main()
{
    std::string s("-615");

    std::string result { baseToBase(s, 7, 16) };
    std::cout << result << std::endl;
    return (0);
}
