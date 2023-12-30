// ? 709. To Lower Case
// ? https://leetcode.com/problems/to-lower-case/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string toLowerCase(string s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }

    return s;
}

int main()
{
}