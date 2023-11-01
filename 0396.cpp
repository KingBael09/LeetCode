// ? 396. Rotate Function
// ? https://leetcode.com/problems/rotate-function/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int maxRotateFunctionBrute(vector<int> &nums)
{
    int n = nums.size();

    deque<int> dq;

    for (auto &i : nums)
    {
        dq.push_back(i);
    }

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += dq[j] * j;
        }
        ans = max(ans, sum);
        dq.push_front(dq.back());
        dq.pop_back();
    }

    return ans;
}

int maxRotateFunction(vector<int> &nums)
{
    int sum = 0;
    int idx = 0;
    int prod = 0;

    for (auto i : nums)
    {
        sum += i;
        prod += i * idx++;
    }

    int ans = prod;
    int sz = idx;

    for (idx; idx > 0; idx--)
    {
        prod += sum - nums[idx - 1] * sz;
        ans = max(ans, prod);
    }

    return ans;
}

// Above is too overkill
int maxRotateFunction(vector<int> &nums)
{
    int sum = 0;
    int prod = 0;
    int sz = nums.size();
    for (int i = 0; i < sz; i++)
    {
        sum += nums[i];
        prod += nums[i] * i;
    }

    int ans = prod;

    for (int i = sz; i > 0; --i)
    {
        prod += sum - nums[i - 1] * sz;
        ans = max(ans, prod);
    }

    return ans;
}

int main()
{
}