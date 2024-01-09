// ? 78. Subsets
// ? https://leetcode.com/problems/subsets/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> ss;

void helper(vector<int> &nums, int idx, vector<int> &ds)
{
    if (nums.size() == idx)
    {
        return ss.push_back(ds);
    }

    ds.push_back(nums[idx]);
    helper(nums, idx + 1, ds);

    ds.pop_back();
    helper(nums, idx + 1, ds);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> ds;

    helper(nums, 0, ds);

    return ss;
}

// TODO: There must also exist a solution using dynamic programming

int main()
{
    vector<int> s{0};

    for (auto i : subsets(s))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}