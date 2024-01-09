// ? 36. Valid Sudoku
// ? https://leetcode.com/problems/valid-sudoku/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isSafe(const vector<vector<char>> &board, int row, int col, char val)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
        if (board[i][col] == val)
        {
            return false;
        }

        int x = 3 * (row / 3) + i / 3;
        int y = 3 * (col / 3) + i % 3;

        if (board[x][y] == val)
        {
            return false;
        }
    }

    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!isSafe(board, i, j, board[i][j]))
            {
                return false;
            }
        }
    }

    return true;
}

// ----------------------------------------------

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<set<char>> rows(9), cols(9), boxes(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            auto val = board[i][j];

            if (val != '.')
            {
                continue;
            }

            int box_idx = 3 * (i / 3) + j / 3;

            if (rows[i].count(val) || cols[j].count(val) || boxes[box_idx].count(val))
            {
                return false;
            }

            rows[i].insert(val);
            cols[j].insert(val);
            boxes[box_idx].insert(val);
        }
    }

    return true;
}

// ----------------------------------------------

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<string> seen;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            auto val = board[i][j];

            if (val == '.')
            {
                continue;
            }

            int box_idx = 3 * (i / 3) + j / 3;

            auto c_a = seen.insert("row " + to_string(i) + val).second;
            auto c_b = seen.insert("col " + to_string(j) + val).second;
            auto c_c = seen.insert("box " + to_string(box_idx) + val).second;

            if (!c_a || !c_b || !c_c)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
}