// ? 796. Rotate String
// ? https://leetcode.com/problems/rotate-string/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
    {
        return false;
    }
    string st = s + s;
    return st.find(goal) != string::npos;
}

int main()
{
}