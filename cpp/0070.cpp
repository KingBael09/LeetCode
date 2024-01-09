// ? 70. Climbing Stairs
// ? https://leetcode.com/problems/climbing-stairs/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int ct = 0;

int helper(int n)
{
    if (n <= 0)
    {
        if (n == 0)
        {
            ct++;
            return 1;
        }
        return 0;
    }

    n--;

    return helper(n) + helper(n - 1);
}

int helperMemoized(int n, vector<int> &save)
{
    if (n <= 0)
    {
        if (n == 0)
        {
            return 1;
        }
        return 0;
    }

    if (save[n] != -1)
    {
        return save[n];
    }
    save[n] = helperMemoized(n - 1, save) + helperMemoized(n - 2, save);

    return save[n];
}

int climbStairs(int n)
{
    vector<int> save(n + 1, -1);

    return helperMemoized(n, save);
}

// TODO: This could be further optimized by just maintaining the last two values and not the whole array.

int main()
{
    cout << climbStairs(5);
}