// ? 39. Combination Sum
// ? https://leetcode.com/problems/combination-sum/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> result;

void solve(int idx, int target, vector<int> &candidates, vector<int> &ds)
{
    if (idx == candidates.size())
    {
        if (target == 0)
        {
            result.push_back(ds);
        }
        return;
    }

    if (candidates[idx] <= target)
    {
        ds.push_back(candidates[idx]);
        solve(idx, target - candidates[idx], candidates, ds);
        ds.pop_back();
    }

    solve(idx + 1, target, candidates, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> ds;
    solve(0, target, candidates, ds);

    return result;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    for (auto i : combinationSum(candidates, target))
    {
        for (auto k : i)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}
