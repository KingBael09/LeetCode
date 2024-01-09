// ? 240. Search a 2D Matrix II
// ? https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool searchMatrixStillBig(vector<vector<int>> &matrix, int target)
{
    int row_limit = 0;
    int col_limit = 0;

    int col_size = matrix.size();
    int row_size = matrix[0].size();

    if (matrix[col_size - 1][row_size - 1] < target)
    {
        return false;
    }

    for (int i = 0; i < col_size; i++)
    {

        int val = matrix[i][0];
        if (val < target)
        {
            col_limit = i;
        }
        if (val == target)
        {
            return true;
        }
    }

    for (int i = 0; i < row_size; i++)
    {
        int val = matrix[0][i];
        if (val < target)
        {
            row_limit = i;
        }
        if (val == target)
        {
            return true;
        }
    }

    for (int i = 0; i <= col_limit; i++)
    {
        for (int j = 0; j <= row_limit; j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

bool searchMatrixDumb(vector<vector<int>> &matrix, int target)
{
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            if (j == target)
            {
                return true;
            }
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int col_size = matrix.size();
    int row_size = matrix[0].size();

    int row_idx = 0;
    int col_idx = row_size - 1;

    while (row_idx < col_size && col_idx >= 0)
    {
        int val = matrix[row_idx][col_idx];

        if (val == target)
        {
            return true;
        }

        if (val < target)
        {
            row_idx++;
        }
        else
        {
            col_idx--;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5}};
    cout << searchMatrix(matrix, 4);
}