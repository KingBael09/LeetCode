// ? 168. Excel Sheet Column Title
// ? https://leetcode.com/problems/excel-sheet-column-title/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string convertToTitle(int columnNumber)
{
    string s;
    while (columnNumber > 0)
    {
        columnNumber--;
        s += ('A' + columnNumber % 26);
        columnNumber /= 26;
    }

    reverse(s.begin(), s.end());

    return s;
}

string convertToTitleSlower(int columnNumber)
{

    deque<char> d;

    while (columnNumber > 0)
    {
        columnNumber--;
        d.push_front('A' + columnNumber % 26);
        columnNumber /= 26;
    }

    return string(d.begin(), d.end());
}

int main()
{
    int someNum = 701;

    cout << convertToTitle(someNum);
}