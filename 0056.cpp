// ? 56. Merge Intervals
// ? https://leetcode.com/problems/merge-intervals/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// very bad solution it takes 2000ms+ time
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size() - 1; i++)
    {

        int j = i + 1;

        while (i >= 0 && j < intervals.size() && intervals[i].back() >= intervals[j].front())
        {
            // if last of current is greater or equal to first of next
            intervals[j][0] = intervals[i].front();
            if (intervals[j].back() < intervals[i].back())
            {
                intervals[j].back() = intervals[i].back();
            }
            intervals.erase(intervals.begin() + i);
            j++;
            i -= 1; // hey it might look ugly but it works
        }
    }
    return intervals;
}

// Hey this is faster but takes a bit more memory
vector<vector<int>> mergeBetter(vector<vector<int>> &intervals)
{
    if (intervals.size() == 1)
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (auto curr : intervals)
    {
        if (ans.empty() || ans.back().back() < curr.front())
        {
            ans.push_back(curr);
        }
        else
        {
            ans.back().back() = max(ans.back().back(), curr.back());
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 8}, {2, 6}, {8, 10}, {15, 18}};

    for (auto i : merge(intervals))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}