// ? 48. Rotate Image
// ? https://leetcode.com/problems/rotate-image/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// ! This is a bad method as it doesn't do it in constant space
void rotateBad(vector<vector<int>> &matrix)
{
    vector<vector<int>> temp = matrix;

    int sz = matrix.size() - 1;

    for (int j = 0; j <= sz; j++)
    {
        for (int i = 0; i <= sz; i++)
        {
            temp[sz - i][sz - j] = matrix[j][i];
        }
    }
    for (int i = 0; i <= sz / 2; i++)
    {
        swap(temp[i], temp[sz - i]);
    }

    matrix = temp;
    temp.clear();

    return;
}

void rotate(vector<vector<int>> &matrix)
{
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (auto &row : matrix)
    {
        reverse(row.begin(), row.end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    rotate(matrix);
    cout << endl;

    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
