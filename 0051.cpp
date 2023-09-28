// ? 51. N-Queens
// ? https://leetcode.com/problems/n-queens/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
// * reminder to self rows->horizontal & columns->vertical

vector<vector<string>> ans;

/**
 * Checks upper diagonal, left side, lower diagonal
 *
 * No need to check right(inc. diagonal) side because it hasn't been placed yet
 * (we are going from left -> right) and we place only one per column so no need to check vertical
 */
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
        ans.push_back(board);
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

// TODO: There is better method for checking isSafe

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));

    helper(0, board, n);

    return ans;
}

int main()
{

    for (auto i : solveNQueens(4))
    {
        for (auto j : i)
        {
            cout << j << endl;
        }
        cout << endl;
    }
}

/* From here onwards, we are going to stop using brain */
