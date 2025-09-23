/*****************************************************************************/
/* Task:    Implement a function that converts a spreadsheet column id to    */
/*          the corresponding integer, with "A" corresponding to 1. For      */
/*          example, you should return 4 for "D", 27 for "AA", 702 for "ZZ"  */
/* Date:    2025-09-23                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <string>

/*
* Time complexity: O(n).
*/
int spreadsheetIdDecoding(const std::string& s)
{
    int result{};

    for (auto c : s)
    {
        int num { c - 'A' + 1};
        result = result * 26 + num;
    }
    return (result);
}

/*
* Variant 2: Implement a function that converts an integer to
*               the spreadsheet column id. For example, you 
*               should return "D" for 4, "AA" for 27 and "ZZ" 
*               for 702.
*/

/*
* Time Complexity: O(log num)
*/
std::string spreadsheetIdEncoding(int num)
{
    std::string id{};

    while (num)
    {
        --num;
        id += num % 26 + 'A';
        num /= 26;
    }
    return {id.rbegin(), id.rend()};
}
int main()
{
    std::string s{"ZZ"};
    int value{702};
    std::string result { spreadsheetIdEncoding(value) };
    std::cout << result << std::endl;
    return (0);
}
