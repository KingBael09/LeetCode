// ? 6. Zigzag Conversion
// ? https://leetcode.com/problems/zigzag-conversion/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows <= 1)
    {
        return s;
    }

    vector<string> list(numRows, "");

    int current = 0;
    bool isEdge = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (current == 0 || current == numRows - 1)
        {
            isEdge = !isEdge;
        }

        list[current] += s[i];

        current += isEdge ? 1 : -1;
    }

    string result = "";

    for (auto &ch : list)
    {
        result += ch;
    }

    return result;
}

int main()
{
    cout << convert("PAYPALISHIRING", 3);
}