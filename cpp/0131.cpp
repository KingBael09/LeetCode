// ? 131. Palindrome Partitioning
// ? https://leetcode.com/problems/palindrome-partitioning/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<string>> res;

bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }

    return true;
}

void helper(int idx, string s, vector<string> &path)
{
    if (idx == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            path.push_back(s.substr(idx, i - idx + 1));
            helper(i + 1, s, path);
            path.pop_back();
        }
    }

    return;
}

vector<vector<string>> partition(string s)
{
    vector<string> path;
    helper(0, s, path);

    return res;
}

int main()
{
    string s = "aab";

    for (auto i : partition(s))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}