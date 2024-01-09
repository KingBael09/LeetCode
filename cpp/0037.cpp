// ? 37. Sudoku Solver
// ? https://leetcode.com/problems/sudoku-solver/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c)
        {
            // check horizontal
            return false;
        }
        if (board[i][col] == c)
        {
            // check vertical
            return false;
        }

        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
        {
            // check region
            return false;
        }
    }

    return true;
}

bool helper(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, row, col, c))
                    {
                        board[row][col] = c;
                        if (!helper(board))
                        {
                            board[row][col] = '.';
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    helper(board);
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}