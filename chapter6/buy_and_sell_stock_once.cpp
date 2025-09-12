/*****************************************************************************/
/* Task:    write a program that takes an array denoting the daily stock     */
/*          price, and returns the maximum profit that could be made by      */
/*          buying and selling one share of that stock.                      */
/* Date:    2025-09-12                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

// Time Complexity: O(n).
double  BuyAndSellStockOnce(const std::vector<double>& prices)
{
    double max_profit {};
    double min_price { std::numeric_limits<double>::max() };

    for (const double& price : prices)
    {
        double current_profit { price - min_price };
        max_profit = std::max(max_profit, current_profit);
        min_price = std::min(min_price, price);
    }
    return (max_profit);
}

// The problem was not explained easy enough to understand
// at first, it is however an easy problem to solve, after understandig it. 

//First variant
// Write a program that takes an array of integers and finds the length of 
// a longest subarray all of whose entries are equal.


int LongestEqualSubarray(const std::vector<int>& nums)
{
    int max_count{};
    int current_length{};

    for (int i{}; i < static_cast<int>(nums.size()); ++i)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            max_count = std::max(max_count, current_length);
            current_length = 1;
        }
        else
            ++current_length;
    }
    max_count = std::max(max_count, current_length);
    return (max_count);
}

int main()
{

    //std::vector<double>    prices{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    std::vector<int>    nums{1, 1, 2, 2, 2, 3, 3, 3, 3, 3 };
    int max_count   { LongestEqualSubarray(nums) };
    // double result   { BuyAndSellStockOnce(prices) };
    std::cout << "Longest equal element subarray: " << max_count << std::endl;
    return (0);
}
