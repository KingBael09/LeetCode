// ? 118. Pascal's Triangle
// ? https://leetcode.com/problems/pascals-triangle/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    if (numRows == 0)
    {
        return {};
    }
    if (numRows == 1)
    {
        return {{1}};
    }

    vector<vector<int>> prev = generate(numRows - 1);

    vector<int> newRow(numRows, 1);

    for (int i = 1; i < numRows - 1; i++)
    {
        newRow[i] = prev.back()[i - 1] + prev.back()[i];
    }

    prev.push_back(newRow);

    return prev;
}

int main()
{
}