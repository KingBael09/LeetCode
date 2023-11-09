// ? 290. Word Pattern
// ? https://leetcode.com/problems/word-pattern/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool wordPattern(string pattern, string s)
{
    stringstream ss(s);
    string str;

    unordered_map<string, char> mp;
    unordered_map<char, string> mp2;

    vector<string> words;

    int pos = 0;

    while (ss >> str)
    {
        words.push_back(str);
    }

    if (words.size() != pattern.size())
    {
        return false;
    }

    for (auto &word : words)
    {
        if (mp.find(word) != mp.end())
        {
            if (mp[word] != pattern[pos])
            {
                return false;
            }
        }
        if (mp2.find(pattern[pos]) != mp2.end())
        {
            if (mp2[pattern[pos]] != word)
            {
                return false;
            }
        }
        else
        {
            mp[word] = pattern[pos];
            mp2[pattern[pos]] = word;
        }
        pos++;
    }

    return true;
}

int main()
{
    cout << wordPattern("abba", "dog cat cat fish");
}