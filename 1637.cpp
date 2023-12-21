// ? 1637. Widest Vertical Area Between Two Points Containing No Points
// ? https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int maxWidthOfVerticalAreaTLE(vector<vector<int>> &points)
{
    int max_col = 0;

    for (auto const &i : points)
    {
        max_col = max(max_col, i.front());
    }

    // if max_col gets some arbitary large value then cols will become too large

    vector<bool> cols(max_col, false);

    for (auto const &i : points)
    {
        cols[i.front()] = true;
    }

    int sz = cols.size();

    max_col = 0;

    int cur = 0;

    while (cur < sz && !cols[cur])
    {
        cur++;
    }

    int last = cur;

    while (cur < sz)
    {
        if (cols[cur])
        {
            max_col = max(max_col, cur - last);
            last = cur;
        }

        cur++;
    }

    return max_col;
}
int maxWidthOfVerticalArea(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const auto &a, const auto &b)
         { return a.front() < b.front(); });

    int max_col = 0;

    for (int i = 1; i < points.size(); i++)
    {
        max_col = max(max_col, points[i].front() - points[i - 1].front());
    }

    return max_col;
}

int main()
{
}