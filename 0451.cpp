// ? 451. Sort Characters By Frequency
// ? https://leetcode.com/problems/sort-characters-by-frequency/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> m;
    priority_queue<pair<int, char>> queue;

    for (auto i : s)
    {
        m[i]++;
    }

    for (auto i : m)
    {
        queue.push({i.second, i.first});
    }
    s.clear();

    while (!queue.empty())
    {
        for (int i = 0; i < queue.top().first; i++)
        {
            s.push_back(queue.top().second);
        }
        queue.pop();
    }

    return s;
}

int main()
{
    cout << frequencySort("tree");
}