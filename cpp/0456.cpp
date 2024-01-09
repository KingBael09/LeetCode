// ? 456. 132 Pattern
// ? https://leetcode.com/problems/132-pattern/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
bool ans = false;

void helper(vector<int> &nums, int idx, vector<int> &stack)
{
    if (ans)
    {
        return;
    }
    if (stack.size() == 3)
    {
        if (stack[0] < stack[2] && stack[1] > stack[2])
        {
            ans = true;
        }
        return;
    }
    if (nums.size() == idx)
    {
        return;
    }

    stack.push_back(nums[idx]);
    helper(nums, idx + 1, stack);
    stack.pop_back();
    helper(nums, idx + 1, stack);
}
// This gives TLE
bool find132patternTLE(vector<int> &nums)
{
    vector<int> st;
    helper(nums, 0, st);

    return ans;
}

bool find132pattern(vector<int> &nums)
{
    stack<int> st;
    int cur_max = INT_MIN;

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        int *curptr = &nums[i]; // for fun

        if (*curptr < cur_max)
        {
            return true;
        }

        while (!st.empty() && st.top() < *curptr)
        {
            cur_max = st.top();
            st.pop();
        }

        st.push(*curptr);
    }

    return false;
}

int main()
{
    vector<int> nums = {3, 5, 0, 3, 4};
    // vector<int> nums = {3, 1, 4, 2};
    // cout << find132patternTLE(nums);
    cout << find132pattern(nums);
}
