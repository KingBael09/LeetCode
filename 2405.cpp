// ? 2405. Optimal Partition of String
// ? https://leetcode.com/problems/optimal-partition-of-string/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int partitionString(string s)
{

    int n = s.size();

    int start = 0, end = 0;

    int count = 1;

    while (end < n)
    {
        for (int i = start; i < end; i++)
        {
            if (s[i] == s[end])
            {
                count++;
                start = end;
                continue;
            }
        }

        end++;
    }

    return count;
}

// This is worse
int arguablyWorsePartitionString(string s)
{
    unordered_map<char, int> m;
    int ct = 1;

    for (auto i : s)
    {
        if (m.find(i) != m.end())
        {
            ct++;
            m.clear();
            m[i]++;
        }
        else
        {
            m[i]++;
        }
    }

    return ct;
}

// TODO: Learn about bitMasking
int betterPartitionString(string s)
{
    int mask = 0;
    int count = 1;

    for (auto i : s)
    {
        if (mask & 1 << (i - 'a'))
        {
            count++;
            mask = 0;
        }
        mask |= 1 << (i - 'a');
    }

    return count;
}

int main()
{
    cout << betterPartitionString("abacaba");
}