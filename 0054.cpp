// ? 54. Spiral Matrix
// ? https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int left_bound = 0, right_bound = matrix[0].size() - 1, top_bound = 0, bottom_bound = matrix.size() - 1;

    while (left_bound <= right_bound && top_bound <= bottom_bound)
    {
        // Goto right
        for (int i = left_bound; i <= right_bound; i++)
        {
            ans.push_back(matrix[top_bound][i]);
        }
        top_bound++;

        // Goto down from where right was left off
        for (int i = top_bound; i <= bottom_bound; i++)
        {
            ans.push_back(matrix[i][right_bound]);
        }
        right_bound--;

        // This helps if the matrix is not square
        if (top_bound > bottom_bound || left_bound > right_bound)
        {
            break;
        }

        // Similarly
        for (int i = right_bound; i >= left_bound; i--)
        {
            ans.push_back(matrix[bottom_bound][i]);
        }
        bottom_bound--;

        // Similarly
        for (int i = bottom_bound; i >= top_bound; i--)
        {
            ans.push_back(matrix[i][left_bound]);
        }
        left_bound++;
    }

    return ans;
}

vector<int> spiralOrderOther(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int top = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

    int count = 0, total = matrix.size() * matrix[0].size();

    while (count < total)
    {
        for (int i = left; i <= right && count < total; i++)
        {
            ans.push_back(matrix[top][i]);
            count++;
        }
        top++;
        for (int i = top; i <= down && count < total; i++)
        {
            ans.push_back(matrix[i][right]);
            count++;
        }
        right--;
        for (int i = right; i >= left && count < total; i--)
        {
            ans.push_back(matrix[down][i]);
            count++;
        }
        down--;
        for (int i = down; i >= top && count < total; i--)
        {
            ans.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    for (auto i : spiralOrder(matrix))
    {
        cout << i << " ";
    }
}