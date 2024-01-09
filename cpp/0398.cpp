// ? 398. Random Pick Index
// ? https://leetcode.com/problems/random-pick-index/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
private:
    unordered_map<int, vector<int>> mp;

public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target)
    {
        int index = rand() % mp[target].size();
        return mp[target][index];
    }
};

int main()
{
}