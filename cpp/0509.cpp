// ? 509. Fibonacci Number
// ? https://leetcode.com/problems/fibonacci-number/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int helper(int n, vector<int> &memo)
{
    if (n < 2)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    return memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
}

int fib(int n)
{
    vector<int> memo(n + 1, -1);
    return helper(n, memo);
}

int fib_brute(int n)
{
    if (n < 2)
    {
        return n;
    }

    return fib_brute(n - 1) + fib_brute(n - 2);
}

int main()
{
}