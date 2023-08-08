// ? https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool main()
{
    vector<int> nums{1, 2, 3, 1};

    unordered_map<int, int> map;

    for (auto val : nums)
    {
        map[val]++;
    }

    bool setBool = false;

    for (auto i : map)
    {
        if (i.second >= 2)
        {
            setBool = true;
        }
    }

    return setBool;
}