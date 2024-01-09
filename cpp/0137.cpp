// ? 137. Single Number II
// ? https://leetcode.com/problems/single-number-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (auto x : nums)
    {
        mp[x]++;
    }

    for (auto i : mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
}

// TODO: This could be done by bit manuplation more efficiently

int main()
{
    vector<int> v{2, 2, 3, 2};

    cout << singleNumber(v);
}