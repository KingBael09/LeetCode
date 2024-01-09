// ? 28. Find the Index of the First Occurrence in a String
// ? https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    auto it = haystack.find(needle);
    if (it != string::npos)
    {
        return it;
    }

    return -1;
}

int main()
{
    string haystack = "leetcode";
    string needle = "leeto";

    cout << strStr(haystack, needle);
}