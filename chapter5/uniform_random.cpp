/**************************************************************************/
/* Task:    How would you implement a random number generator that         */
/*          generates a random integer i between a and b, inclusive, given */
/*          a random number generator that produces 0 or 1 with equal      */
/*          probability? All values in [a,b] should be equally likely.     */
/* Date:    2025-08-26                                                     */
/* Author:  Success Daniel                                                 */
/* *************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// generates either 0 or 1. just as a coin flip generates head or tail
int ZeroOneRandomGen()
{
    return (rand() % 2);
}

int UniformRandom(int lower_bound, int upper_bound)
{
    int result { };
    // in plain text, this is the number of players or friends.
    int number_of_outcomes { upper_bound - lower_bound + 1 };

    srand(time(NULL));
    do {
        result = 0;
        //how many times we need to flip the coin to produce
        //bit fields that maps to a player or friend.
        //(1 << i) is equivalent to 2 to the power i.
        for (int i { }; (1 << i) < number_of_outcomes; ++i)
            result = (result << 1) | ZeroOneRandomGen();
        // if we generate a result that is beyond the number of players
        // participating, we retry the result generation.
    } while (result >= number_of_outcomes); 
    return (result + lower_bound);
}

/*
    What I learned:
        This exercise was not straigtforward to process at first.
    The idea is that 6 friends need to select who would drive,
    where everyone has similar chances of being selected.
    How would they do that, if they can only use a coin to generate the result.
    I had to understand how using the coin and mapping results to friends
    would work, and the problem that occurs if the number of friends in
    this case is not a power of 2.
    If the number is not a power of 2, we cannot really use a coin
    to map out possible results in an unbiased way. The solution is
    to find the the smallest power of 2 that is greater than 6, which is 8.
    Use that to map the 6 friends, if the result generated is bigger than 6,
    we repeat the result generation.
    I.e since 2 to the power of 3 is 8 but we only have 6 frineds. meaning 2
    numbers 7 and 8 does not map to any friend. If we generate 7 or 8, we 
    repeat the process, which is still unbiased since every retry applies 
    across friends. 
*/
int main()
{
    int num_of_players;

    cout << "Enter number of friends: ";
    cin >> num_of_players;
    int result { UniformRandom(1, num_of_players) };
    cout << "Friend " << result << " is the driver" << endl;
    return (0);
}
