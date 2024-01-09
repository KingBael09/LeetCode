// ? 77. Combinations
// ? https://leetcode.com/problems/combinations/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> ans;

void helper(int k, int start, const vector<int> &nums, vector<int> &ds)
{

    if (ds.size() == k)
    {
        return ans.push_back(ds);
    }

    if (start == nums.size())
    {
        return;
    }

    ds.push_back(nums[start]);

    helper(k, start + 1, nums, ds);

    ds.pop_back();

    helper(k, start + 1, nums, ds);
}

vector<vector<int>> combine(int n, int k)
{
    vector<int> nums(n);

    iota(nums.begin(), nums.end(), 1);

    vector<int> ds;

    helper(k, 0, nums, ds);

    return ans;
}

// ---

vector<vector<int>> ans;

void helper(int pos, vector<int> &ds, const int &n, const int &k)
{
    if (ds.size() == k)
    {
        return ans.push_back(ds);
    }

    for (; pos <= n; pos++)
    {
        ds.push_back(pos);
        helper(pos + 1, ds, n, k);
        ds.pop_back();
    }
}

vector<vector<int>> combine_without_extra_vector(int n, int k)
{
    vector<int> ds;
    helper(1, ds, n, k);

    return ans;
}

int main()
{
    for (auto i : combine(4, 2))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}