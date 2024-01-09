// ? 2706. Buy Two Chocolates
// ? https://leetcode.com/problems/buy-two-chocolates/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int buyChoco(vector<int> &prices, int money)
{
    int first = INT_MAX;
    int second = INT_MAX;

    for (const auto &i : prices)
    {
        if (i < second)
        {
            first = exchange(second, i);
        }
        else
        {
            first = min(first, i);
        }
    }

    int left = money - first - second;

    return left >= 0 ? left : money;
}