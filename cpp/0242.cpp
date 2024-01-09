// ? 242. Valid Anagram
// ? https://leetcode.com/problems/valid-anagram/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Very bad method
bool getAnswer(string s, string t)
{
    vector<char> l1;
    vector<char> l2;

    if (s.length() != t.length())
    {
        return false;
    }

    for (auto i : s)
    {
        l1.push_back(i);
    }
    for (auto i : t)
    {
        l2.push_back(i);
    }

    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());

    for (int i = 0; i < l1.size(); i++)
    {
        if (l1[i] != l2[i])
        {
            return false;
        }
    }

    return true;
}

bool getAnsFaster(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s != t)
    {
        return false;
    }

    return true;
}

int main()
{
    string s = "aa";
    string t = "bb";

    bool ans = getAnswer(s, t);

    cout << ans;
}