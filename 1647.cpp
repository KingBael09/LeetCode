// ? 1647. Minimum Deletions to Make Character Frequencies Unique
// ? https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int minDeletions(string s)
{
    int count = 0;

    unordered_map<char, int> freq;
    unordered_set<int> st;

    for (auto i : s)
    {
        freq[i]++;
        // add to freq
    }

    for (auto f : freq)
    {
        int t = f.second;
        while (st.find(t) != st.end() && t != 0)
        {
            // reduce the term and increse the count if it already exists in the set
            count++;
            t--;
        }
        st.insert(t);
    }

    return count;
}

int minDeletionsBetter(string s)
{
    int count = 0;
    vector<int> freq(26, 0);
    unordered_set<int> st;

    for (auto c : s)
    {
        freq[c - 'a']++;
    }

    for (auto i : freq)
    {
        int curr = i;
        if (curr == 0)
        {
            continue;
        }
        while (st.find(curr) != st.end() && curr != 0)
        {
            count++;
            curr--;
        }
        st.insert(curr);
    }

    return count;
}

int main()
{
    // cout << minDeletions("aaabbbcc");
    cout << minDeletionsBetter("bbcebab");
}