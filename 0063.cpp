// ? 63. Unique Paths II
// ? https://leetcode.com/problems/unique-paths-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int paths(int i, int j, const vector<vector<int>> &obstacleGrid)
{
    int last_row = obstacleGrid.size() - 1;
    int last_col = obstacleGrid[0].size() - 1;

    if (i > last_row || j > last_col || obstacleGrid[i][j] == 1)
    {
        return 0;
    }

    if (i == last_row && j == last_col)
    {
        // we have reached the destination
        return 1;
    }

    return paths(i + 1, j, obstacleGrid) + paths(i, j + 1, obstacleGrid);
}

int uniquePathsWithObstaclesWithoutMemo(vector<vector<int>> &obstacleGrid)
{
    return paths(0, 0, obstacleGrid);
}

int pathsWithMemo(int i, int j, const vector<vector<int>> &obstacleGrid, vector<vector<int>> &memo)
{
    int last_row = obstacleGrid.size() - 1;
    int last_col = obstacleGrid[0].size() - 1;

    if (i > last_row || j > last_col || obstacleGrid[i][j] == 1)
    {
        return 0;
    }

    if (i == last_row && j == last_col)
    {
        return 1;
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int down = pathsWithMemo(i + 1, j, obstacleGrid, memo);
    int right = pathsWithMemo(i, j + 1, obstacleGrid, memo);

    memo[i][j] = down + right;

    return memo[i][j];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector<vector<int>> memo(row, vector<int>(col, -1));

    return pathsWithMemo(0, 0, obstacleGrid, memo);
}

// TODO: Note that there could be more space optimization and iterative approaches

int main()
{
}