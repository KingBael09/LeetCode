// ? 441. Arranging Coins
// ? https://leetcode.com/problems/arranging-coins/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Naive method

int arrangeCoins(int n)
{
    long i = 1;

    while (i * (i + 1) / 2 <= n)
    {
        i++;
    }

    return --i;
}

// Calculative Method

int arrangeCoinsBetter(int n)
{
    return floor(sqrt(2 * (long)n + 0.25) - 0.5);
}

int main()
{
}