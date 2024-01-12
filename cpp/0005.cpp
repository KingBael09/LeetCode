// ? 5. Longest Palindromic Substring
// ? https://leetcode.com/problems/longest-palindromic-substring/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string expand(int left, int right, const string &str)
{
    while (left >= 0 && right < str.size() && str[left] == str[right])
    {
        left--;
        right++;
    }

    auto re = str.substr(left + 1, right - left - 1);
    return re;
}

string longestPalindrome(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        string single_s = expand(i, i, s);
        string double_s = expand(i, i + 1, s);

        if (single_s.size() > res.size())
        {
            res = single_s;
        }
        if (double_s.size() > res.size())
        {
            res = double_s;
        }
    }

    return res;
}

int main()
{

    auto s = longestPalindrome("babad");
    cout << s;
}