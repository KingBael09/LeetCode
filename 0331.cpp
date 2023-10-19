// ? 331. Verify Preorder Serialization of a Binary Tree
// ? https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isValidSerialization(string preorder)
{
    vector<string> vec;

    int start = 0;
    int sz = preorder.size();

    for (int end = 0; end < sz; end++)
    {
        if (preorder[end] == ',')
        {
            vec.push_back(preorder.substr(start, end - start));
            start = end + 1;
        }
        if (end == sz - 1)
        {
            vec.push_back(preorder.substr(start));
        }
    }

    int diff = 1;

    for (auto i : vec)
    {
        if (--diff < 0)
        {
            return false;
        }

        if (i != "#")
        {
            diff += 2;
        }
    }

    return diff == 0;
}

bool shorterIsValidSerialization(string preorder)
{
    for (auto &i : preorder)
    {
        if (i == ',')
        {
            i = ' ';
        }
    }

    stringstream ss(preorder);

    int diff = 1;

    string token;

    while (ss >> token)
    {
        if (--diff < 0)
        {
            return false;
        }

        if (token != "#")
        {
            diff += 2;
        }
    }

    return diff == 0;
}

bool moreShorterIsValidSerialization(string preorder)
{

    stringstream ss(preorder);

    int diff = 1; // current is counted and we can look for next

    string token;

    while (getline(ss, token, ','))
    {
        if (--diff < 0) // if no lives we die
        {
            return false;
        }

        if (token != "#")
        {
            diff += 2; // if is number we get two lives
        }
    }

    return diff == 0;
}

int main()
{
    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
}