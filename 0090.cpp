// ? 90. Subsets II
// ? https://leetcode.com/problems/subsets-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> ans;

void helper(int idx, vector<int> &nums, vector<int> &ds)
{
    if (idx == nums.size())
    {
        if (find(ans.begin(), ans.end(), ds) == ans.end())
        {
            ans.push_back(ds);
        }
        return;
    }

    // pick
    ds.push_back(nums[idx]);
    helper(idx + 1, nums, ds);

    ds.pop_back();

    helper(idx + 1, nums, ds);
}

// Very very bad solution basically bruteforce
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{

    vector<int> ds;

    sort(nums.begin(), nums.end());

    helper(0, nums, ds);

    sort(ans.begin(), ans.end());

    return ans;
}

// Better Solution

void betterHelper(int idx, vector<int> &nums, vector<int> &ds)
{
    ans.push_back(ds);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
        {
            continue;
        }
        ds.push_back(nums[i]);
        betterHelper(i + 1, nums, ds);
        ds.pop_back();
    }

    return;
}

vector<vector<int>> subsetsWithDupBetter(vector<int> &nums)
{
    vector<int> ds;
    sort(nums.begin(), nums.end());
    betterHelper(0, nums, ds);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    for (auto i : subsetsWithDupBetter(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
