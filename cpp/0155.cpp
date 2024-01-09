// ? 155. Min Stack
// ? https://leetcode.com/problems/min-stack/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            return st.push({val, val});
        }
        // else
        // {
        //     int prev = st.top().second;
        //     if (prev >= val)
        //     {
        //         st.push({val, val});
        //     }
        //     else
        //     {
        //         st.push({val, prev});
        //     }
        // }

        // Above could be shortened to

        return st.push({val, min(st.top().second, val)});
    }

    void pop()
    {
        return st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
}