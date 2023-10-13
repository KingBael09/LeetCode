// ? 47. Permutations II
// ? https://leetcode.com/problems/permutations-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> ans;
void helper(int idx, vector<int> &nums, vector<int> &ds, vector<bool> &used)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i])
        {
            continue;
        }

        ds.push_back(nums[i]);
        used[i] = true;
        helper(i, nums, ds, used);
        used[i] = false;
        ds.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> ds;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    helper(0, nums, ds, used);

    return ans;
}

// WTF is this solution
vector<vector<int>> permuteUnique2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    res.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
    {
        res.push_back(nums);
    }
    return res;
}

int main()
{
    vector<int> s{1, 1, 2};
    permuteUnique2(s);
}