//? https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int getMaxLenSubstr(string s)
{
    int len = s.length();

    int start = 0;
    int end = 0;
    int longestSublen = 0;

    unordered_map<char, int> mp;

    while (end < len)
    {
        char current = s[end];

        if (mp.find(current) != mp.end()) // if element present then move start to currents position
        {
            start = max(start, mp[current] + 1);
        }

        mp[current] = end;

        longestSublen = max(longestSublen, end - start + 1);

        end++;
    }

    return longestSublen;
}

int main()
{
    string str = "dvdf";

    int len = getMaxLenSubstr(str);

    cout << endl
         << len;
}