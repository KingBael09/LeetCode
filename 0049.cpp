// ? 49. Group Anagrams
// ? https://leetcode.com/problems/group-anagrams/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> result;

    unordered_map<string, vector<string>> mp;

    for (auto i : strs)
    {
        string temp = i;
        sort(temp.begin(), temp.end());
        mp[temp].emplace_back(i);
    }

    for (auto i : mp)
    {
        result.emplace_back(i.second);
    }

    return result;
}

int main()
{
    vector<string> strset{"eat", "tea", "tan", "ate", "nat", "bat"};

    for (auto i : groupAnagrams(strset))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}