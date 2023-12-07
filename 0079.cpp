// ? 79. Word Search
// ? https://leetcode.com/problems/word-search/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool find(vector<vector<char>> &board, const string &word, int row, int col, int idx)
{
    if (idx == word.size())
    {
        return true;
    }

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx])
    {
        // fail in case of out of bound or mismatch
        return false;
    }

    auto temp = board[row][col];
    board[row][col] = ' '; // placeholder

    idx++;

    auto found = find(board, word, row + 1, col, idx) ||
                 find(board, word, row, col + 1, idx) ||
                 find(board, word, row - 1, col, idx) ||
                 find(board, word, row, col - 1, idx);

    board[row][col] = temp;

    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (find(board, word, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
}