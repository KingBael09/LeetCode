// ? 150. Evaluate Reverse Polish Notation
// ? https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (auto &token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            auto num2 = st.top();
            st.pop();
            auto num1 = st.top();
            st.pop();

            if (token == "+")
            {
                st.push(num1 + num2);
            }
            else if (token == "-")
            {
                st.push(num1 - num2);
            }
            else if (token == "*")
            {
                st.push(num1 * num2);
            }
            else if (token == "/")
            {
                st.push(num1 / num2);
            }
        }
        else
        {
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main()
{
}