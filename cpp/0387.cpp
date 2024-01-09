// ? 387. First Unique Character in a String
// ? https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> m;

    for (char &i : s)
    {
        m[i]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    cout << firstUniqChar("leetcode");
}