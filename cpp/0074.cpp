// ? 74. Search a 2D Matrix
// ? https://leetcode.com/problems/search-a-2d-matrix/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int col_size = matrix.size();
    int row_size = matrix.front().size();

    int low = 0;
    int high = col_size * row_size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / row_size;
        int col = mid % row_size;

        if (matrix[row][col] == target)
        {
            return true;
        }

        if (matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{
}