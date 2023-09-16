// ? 20. Valid Parentheses
// ? https://leetcode.com/problems/valid-parentheses/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else
        {
            if (st.empty() ||
                (i == ')' && st.top() != '(') ||
                (i == '}' && st.top() != '{') ||
                (i == ']' && st.top() != '['))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    return st.empty();
}

int main()
{
    // Too lazy to write driver code
}