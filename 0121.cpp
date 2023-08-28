// ? 121. Best Time to Buy and Sell Stock
// ? https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int maxProfitBruteForce(vector<int> &prices)
{
    int len = prices.size();

    int profit = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            profit = max(profit, prices[j] - prices[i]);
        }
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;

    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main()
{
    vector<int> l{2, 4, 1};

    cout << maxProfit(l);
}