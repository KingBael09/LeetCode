// ? 73. Set Matrix Zeroes
// ? https://leetcode.com/problems/set-matrix-zeroes/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This solution uses m.n space
void setZeroes(vector<vector<int>> &matrix)
{
    vector<vector<int>> snap = matrix;
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (snap[row][col] == 0)
            {
                for (int i = 0; i < rows; i++)
                {
                    matrix[i][col] = 0;
                }
                for (int i = 0; i < cols; i++)
                {
                    matrix[row][i] = 0;
                }
            }
        }
    }
}

// This takes O(m+n) space
void setZerosBetter(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<bool> row_list(rows, false);
    vector<bool> col_list(cols, false);

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 0)
            {
                row_list[row] = true;
                col_list[col] = true;
            }
        }
    }
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (row_list[row] || col_list[col])
            {
                matrix[row][col] = 0;
            }
        }
    }
}

// TODO: Still some optimizations can be made to O(1) space

int main()
{
}