// ? 1823. Find the Winner of the Circular Game
// ? https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int helper(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }

    return (helper(n - 1, k) + k) % n;
}

int findTheWinner(int n, int k)
{
    return helper(n, k) + 1;
}

int findTheWinnerLinear(int n, int k)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + k) % i;
    }

    return ans + 1;
}

int main()
{
    findTheWinner(5, 1);
}