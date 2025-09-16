/*****************************************************************************/
/* Task:    write a program that takes an integer argument and returns all   */
/*          the primes between 1 and that integer.                           */
/* Date:    2025-09-15                                                       */
/* Author:  Success Daniel                                                   */
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>


bool    isPrime(int num)
{
    if (!(num % 2))
        return (false);
    for (int i { 3 }; i <= sqrt(num); ++i)
        if (!(num % i))
            return (false);
    return (true);
}

// Brute force approach
std::vector<int>    enumerateAllPrimes(int num)
{
    std::vector<int>    primes;

    if (num == 2)
         return {};
    primes.emplace_back(2);
    for (int i { 3 }; i <= num; ++i)
        if (isPrime(i))
            primes.emplace_back(i);
    return (primes);
}

// Sieve of Eratosthenes
// Time Complexity: O(n log log n)
// Space Complexity: O(n)
std::vector<int>    GeneratePrimes(int n)
{
    std::vector<int>    primes;
    std::deque<bool>    is_prime(n + 1, true);
    
    is_prime[0] = is_prime[1] = false;
    for (int p{ 2 }; p <= n; ++p)
    {
        if (is_prime[p])
        {
            primes.emplace_back(p);
            // Sieve p's multiples.
            // We use p * p, to avoid visiting indices we have already
            // seen before, say p is 5, a multiple of 5 is 10, but we have
            // already visited index 10, when we visited the multiples of 2.
            // So if p were 3, we move straight to 9, because we have seen 6
            // when computed the multiples of 2.
            for (int j{ p * p }; j <= n; j += p)
                is_prime[j] = false;
        }
    }
    return (primes);
}

int main()
{
    std::vector<int>    primes { GeneratePrimes(17) };

    for (auto i : primes)
        std::cout << i << " ";
    std::cout << std::endl;
    return (0);
}
