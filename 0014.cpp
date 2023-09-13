// ? 14. Longest Common Prefix
// ? https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string longestCommonPrefixSlow(vector<string> &strs)
{
    string common = "";
    int minSize = INT_MAX;

    for (auto i : strs)
    {
        minSize = min(minSize, (int)i.size());
    }

    cout << minSize << endl;

    for (int i = 0; i < minSize; i++)
    {
        char c = strs[0][i];
        for (auto j : strs)
        {
            if (j[i] != c)
            {
                return common;
            }
        }
        common += c;
    }

    return common;
}

string longestCommonPrefixFast(vector<string> &strs)
{
    string common = "";

    sort(strs.begin(), strs.end());
    // this makes the start and end elements the most different so if we get the common prefix here such can be said for all the strings

    auto start = strs.front();
    auto end = strs.back();

    for (int i = 0; i < min(start.size(), end.size()); i++)
    {
        if (start[i] != end[i])
        {
            return common;
        }
        common.push_back(start[i]);
    }

    return common;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefixFast(strs);
}
