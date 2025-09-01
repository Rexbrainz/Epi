/**************************************************************************/
/* Task:    Write a program which takes as input two strings s and t of   */
/*          bits encoding binary numbers Bs and Bt, respectively, and     */
/*          returns a new string of bits representing the number Bs + Bt  */
/* Date:    2025-09-01                                                    */
/* Author:  Success Daniel                                                */
/* ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

// My long and complicated approach
// Time complexity: O(n to the power of 2).
std::string addBits(std::string& s, std::string& t)
{
    int         carry_in{};
    int         carry_out{};
    int         s_len = s.length();
    int         t_len = t.length();
    std::string result;
    
    while (s_len || t_len)
    {
        int int_s{}, int_t{};
        if (s_len)
            int_s = s[--s_len] - '0';
        if (t_len)
            int_t = t[--t_len] - '0';
        int int_r { int_s + int_t + carry_in };
        if (int_r == 2)
        {
            int_r = 0;
            carry_out = 1;
        }
        else if (int_r == 3)
        {
            int_r = 1;
            carry_out = 1;
        }
        result.insert(result.begin(), int_r + '0');
        carry_in = 0;
        if (carry_out)
        {
            carry_in = 1;
            carry_out = 0;
        }
    }
    if (carry_in)
    {
        if (result[0] == '1')
        {
            result[0] = '0';
            result.insert(result.begin(), '1');
        }
        else
            result.insert(result.begin(), '1');
    }
    return (result);
}

// Better and less complicated approach
std::string bits_addition(const std::string& s, const std::string& t)
{
    int         i = s.length() - 1;
    int         j = t.length() - 1;
    int         carry{};
    std::string result;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum { carry };
        if (i >= 0)
            sum += s[i--] - '0';
        if (j >= 0)
            sum += t[j--] - '0';
        result.push_back((sum % 2) + '0');
        carry = sum / 2;
    }
    std::reverse(result.begin(), result.end());
    return (result);
}

int main()
{
    std::string s { '1', '0', '1', '1' };
    std::string t { '1', '1', '0' };
    std::string result { bits_addition(s, t) };
    for (auto ch : result)
        std::cout << ch << " ";
    std::cout << std::endl;
    return (0);
}
