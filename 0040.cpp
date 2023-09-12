#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> ans;

void helper(int idx, int target, vector<int> &candidates, vector<int> &ds)
{
    if (idx == candidates.size() - 1)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        return;
    }
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    ds.push_back(candidates[idx]);

    helper(idx + 1, target - candidates[idx], candidates, ds);

    ds.pop_back();

    helper(idx + 1, target, candidates, ds);
}
// ! Not a performant solution
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> ds;

    sort(candidates.begin(), candidates.end());

    helper(0, target, candidates, ds);

    sort(ans.begin(), ans.end());
    // I need to think of a way to not have duplicates in the first place
    auto it = unique(ans.begin(), ans.end());

    ans.resize(distance(ans.begin(), it));

    return ans;
}

/**
 * Better Sol
 */

vector<vector<int>> betterAns;

void betterHelper(int idx, int target, vector<int> &candidates, vector<int> &ds)
{
    if (target == 0)
    {
        betterAns.push_back(ds);
        return;
    }

    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        ds.push_back(candidates[i]);
        betterHelper(i + 1, target - candidates[i], candidates, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSumBetter(vector<int> &candidates, int target)
{
    vector<int> ds;
    sort(candidates.begin(), candidates.end());

    betterHelper(0, target, candidates, ds);
}

int main()
{
    vector<int> candidates = {14, 6, 25, 9, 30, 20, 33, 34, 28, 30, 16, 12, 31, 9, 9, 12, 34, 16, 25, 32, 8, 7, 30, 12, 33, 20, 21, 29, 24, 17, 27, 34, 11, 17, 30, 6, 32, 21, 27, 17, 16, 8, 24, 12, 12, 28, 11, 33, 10, 32, 22, 13, 34, 18, 12};
    int target = 27;

    for (auto i : combinationSum2(candidates, target))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
