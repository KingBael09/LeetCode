// ? 392. Is Subsequence
// ? https://leetcode.com/problems/is-subsequence/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isSubsequence(string s, string t)
{
    deque<char> dq;
    for (auto i : s)
    {
        dq.push_back(i);
    }

    for (auto i : t)
    {
        if (dq.empty())
        {
            return true;
        }

        if (dq.front() == i)
        {
            dq.pop_front();
        }
    }

    if (dq.empty())
    {
        return true;
    }

    return false;
}

bool isSubsequenceBetter(string s, string t)
{
    int idx = 0;
    int size = s.size();

    for (auto i : t)
    {
        if (s[idx] == i)
        {
            idx++;
        }
        if (idx == size)
        {
            // case of early exit
            return true;
        }
    }

    return idx == size;
}

// reducing above

bool isSubsequenceBetterSmaller(string s, string t)
{
    if (s == t)
    {
        return true;
    }

    int idx = 0;
    for (auto i : t)
    {
        idx += i == s[idx]; // this is legit genius
        if (s.size() == idx)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << isSubsequenceBetter("abc", "ahbgdc");
}