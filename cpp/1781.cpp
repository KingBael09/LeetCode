// ? 1781. Sum of Beauty of All Substrings
// ? https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int helperTLE(string str)
{
    unordered_map<char, int> mp;

    for (auto ch : str)
    {
        mp[ch]++;
    }

    int mn = INT_MAX;
    int mx = INT_MIN;

    for (auto it : mp)
    {
        mn = min(mn, it.second);
        mx = max(mx, it.second);
    }

    return mx - mn;
}

int beautySumTLE(string s)
{
    int beauty = 0;
    int sz = s.size();

    for (int i = 0; i < sz; i++)
    {
        string str = "";
        for (int j = i; j < sz; j++)
        {
            str += s[j];
            if (str.size() > 2)
            {
                beauty += helperTLE(str);
            }
        }
    }

    return beauty;
}

int beautySum(string s)
{
    int beauty = 0;
    int sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        unordered_map<char, int> m;
        for (int j = i; j < sz; j++)
        {
            m[s[j]]++;
            int mn = 500, mx = 1; // Dammit Constraints

            for (auto [ch, count] : m)
            {
                mn = min(mn, count);
                mx = max(mx, count);
            }

            beauty += mx - mn;
        }
    }

    return beauty;
}

int main()
{
    cout << beautySum("abcd");
}