// ? 52. N-Queens II
// ? https://leetcode.com/problems/n-queens-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
// * reminder to self rows->horizontal & columns->vertical

int ct = 0;

bool isSafe(int row, int col, vector<string> &board, int size)
{
    int baseRow = row, baseCol = col;

    while (row >= 0 && col >= 0)
    {
        // checking upper diagonal
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    // reset
    row = baseRow;
    col = baseCol;

    while (row < size && col >= 0)
    {
        // checking lower diagonal
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }

    // reset
    row = baseRow;
    col = baseCol;

    while (col >= 0)
    {
        // checking left side
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }

    return true;
}
void helper(int col, vector<string> &board, int size)
{
    if (col == size) // n-1 columns have been checked
    {
        ct++;
        return;
    }

    for (int row = 0; row < size; row++)
    {
        if (isSafe(row, col, board, size))
        {
            board[row][col] = 'Q';
            helper(col + 1, board, size);
            board[row][col] = '.';
        }
    }
}
int totalNQueens(int n)
{
    vector<string> board(n, string(n, '.'));

    helper(0, board, n);

    return ct;
}

int main()
{
}