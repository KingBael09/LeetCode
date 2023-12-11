// ? 62. Unique Paths
// ? https://leetcode.com/problems/unique-paths/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int paths(int idx_col, int idx_row)
{
    if (idx_col <= 0 || idx_row <= 0)
    {
        return 1;
    }

    return paths(idx_col - 1, idx_row) + paths(idx_col, idx_row - 1);
}

int uniquePathsRecursive(int m, int n)
{
    return paths(m - 1, n - 1);
}

// With Memoization

int helper(int m, int n, vector<vector<int>> &dp)
{
    if (m <= 0 || n <= 0)
    {
        return 1;
    }

    auto val = &dp[m][n];

    if (*val == -1)
    {
        *val = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }

    return *val;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(m - 1, n - 1, dp);
}

int main()
{
}