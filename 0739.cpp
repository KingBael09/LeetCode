// ? 739. Daily Temperatures
// ? https://leetcode.com/problems/daily-temperatures/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    stack<int> st;

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int next = st.top();
            st.pop();

            ans[next] = i - next;
        }

        st.push(i);
    }

    return ans;
}

int main()
{
}