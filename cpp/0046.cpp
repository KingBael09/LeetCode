// ? 46. Permutations
// ? https://leetcode.com/problems/permutations/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> ans;

void helper(vector<int> &nums, vector<int> &ds, unordered_map<int, bool> &mp)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (auto i : nums)
    {
        if (mp[i] == false)
        {
            ds.push_back(i);
            mp[i] = true;
            helper(nums, ds, mp);
            mp[i] = false;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ds;
    unordered_map<int, bool> mp;
    for (auto i : nums)
    {
        mp[i] = false;
    }

    helper(nums, ds, mp);

    return ans;
}

// Better method by swapping
void betterHelper(int idx, vector<int> &nums)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]); // modify with future element
        betterHelper(idx + 1, nums);
        swap(nums[idx], nums[i]); // undo modification
    }

    return;
}

vector<vector<int>> permuteBetter(vector<int> &nums)
{
    betterHelper(0, nums);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    for (auto i : permuteBetter(nums))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
