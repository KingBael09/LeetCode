// ? 59. Spiral Matrix II
// ? https://leetcode.com/problems/spiral-matrix-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));

    int total = n * n;

    int count = 1;

    int top_bound = 0, bottom_bound = n - 1, left_bound = 0, right_bound = n - 1;

    while (count <= total)
    {
        for (int i = left_bound; i <= right_bound; i++)
        {
            matrix[top_bound][i] = count;
            count++;
        }
        top_bound++;

        for (int i = top_bound; i <= bottom_bound; i++)
        {
            matrix[i][right_bound] = count;
            count++;
        }
        right_bound--;

        for (int i = right_bound; i >= left_bound; i--)
        {
            matrix[bottom_bound][i] = count;
            count++;
        }
        bottom_bound--;

        for (int i = bottom_bound; i >= top_bound; i--)
        {
            matrix[i][left_bound] = count;
            count++;
        }
        left_bound++;
    }

    return matrix;
}

int main()
{
}