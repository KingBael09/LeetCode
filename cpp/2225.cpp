// ? 2225. Find Players With Zero or One Losses
// ? https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    unordered_map<int, int> winners, losers;

    for (auto i : matches)
    {
        auto winner = i.front();
        auto loser = i.back();

        if (!losers.count(winner))
        {
            winners[winner]++;
        }

        losers[loser]++;

        if (winners.count(loser))
        {
            winners.erase(loser);
        }
    }

    vector<int> first;

    for (auto i : winners)
    {
        first.push_back(i.first);
    }

    vector<int> second;

    for (auto i : losers)
    {
        if (i.second == 1)
        {
            second.push_back(i.first);
        }
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    return {first, second};
}

vector<vector<int>> findWinnersOther(vector<vector<int>> &matches)
{
    unordered_map<int, int> losers;
    vector<int> win, lost;

    for (auto i : matches)
    {
        auto loser = i.back();

        losers[loser]++;
    }

    for (auto i : losers)
    {
        if (i.second == 1)
        {
            lost.push_back(i.first);
        }
    }

    for (auto i : matches)
    {
        auto winner = i.front();
        auto loser = i.back();

        if (!losers.count(winner))
        {
            win.push_back(winner);
            losers[winner]++; // so that we don't add the value again
        }
    }

    sort(win.begin(), win.end());
    sort(lost.begin(), lost.end());

    return {win, lost};
}

int main()
{
    vector<vector<int>> a = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    findWinners(a);
}