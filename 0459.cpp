// ? 459. Repeated Substring Pattern
// ? https://leetcode.com/problems/repeated-substring-pattern/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool repeatedSubstringON(string s)
{
    int n = s.length() - 1;

    string st = (s + s).substr(1, n * 2);

    return st.find(s) != string::npos;
}

bool MorePerformance(string s)
{
    return (s + s).substr(1, (s.length() - 1) * 2).find(s) != string::npos;
}

int main()
{
    string s = "abcabc";

    if (repeatedSubstringON(s))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}