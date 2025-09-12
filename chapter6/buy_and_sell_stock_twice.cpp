/*****************************************************************************/
/* Task:    write a program that computes the maximum profit that can be     */
/*          made by buying and selling a share at most twice. The second     */
/*          buy must be made on another date after the first sale.           */
/* Date:    2025-09-12                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>


// Very tricky problem, i need to review it more times
// Time Complexity: O(n).
double  BuyAndSellStockeTwice(const std::vector<double>& prices)
{
    double max_total_profit{};
    std::vector<double> first_buy_sell_profits(prices.size(), 0);
    double  min_price_so_far { std::numeric_limits<double>::max() };

    // Forward phase. For each day, we record maximum profit if we
    // sell on that day.
    for (int i{}; i < static_cast<int>(prices.size()); ++i)
    {
        min_price_so_far = std::min(min_price_so_far, prices[i]);
        max_total_profit = 
            std::max(max_total_profit, prices[i] - min_price_so_far);
        first_buy_sell_profits[i] = max_total_profit;
    }

    // Backward phase. For each day, find the maximum profit if we make
    // the second buy on that day.
    double max_price_so_far { std::numeric_limits<double>::min() };
    for (int i = prices.size() - 1; i > 0; --i)
    {
        max_price_so_far = std::max(max_price_so_far, prices[i]);
        max_total_profit = 
            std::max(max_total_profit, 
                max_price_so_far - prices[i] + first_buy_sell_profits[i - 1]);
    }
    return (max_total_profit);
}
