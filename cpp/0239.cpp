// ? 239. Sliding Window Maximum
// ? https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindowBruteForce(vector<int> &nums, int k)
{
    int start = 0, end = k - 1;

    int len = nums.size();

    vector<int> ans;

    while (end < len)
    {
        int maxInWindow = -INT_MAX;
        for (int i = 0; i < k; i++)
        {
            maxInWindow = max(maxInWindow, nums[start + i]);
        }

        ans.push_back(maxInWindow);

        end++;
        start++;
    }

    return ans;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int start = 0, end = 0;

    int len = nums.size();

    vector<int> ans;

    deque<int> pos;

    // While loop can be substitued with for look
    while (end < len)
    {
        while (!pos.empty() && nums[end] > nums[pos.back()])
        {
            pos.pop_back();
        }

        pos.push_back(end);

        if (!pos.empty() && start > pos.front())
        {
            pos.pop_front();
        }

        if (end + 1 >= k)
        {
            ans.push_back(nums[pos.front()]);
            start++;
        }

        end++;
    }

    return ans;
}

vector<int> maxSlidingWindowBetter(vector<int> &nums, int k)
{
    int len = nums.size();

    deque<int> pos;

    vector<int> ans;

    for (int i = 0; i < len; i++)
    {
        if (!pos.empty() && pos.front() <= i - k)
        {
            pos.pop_front();
        }

        while (!pos.empty() && nums[i] >= nums[pos.back()])
        {
            pos.pop_back();
        }

        pos.push_back(i);

        if (i + 1 >= k)
        {
            ans.push_back(nums[pos.front()]);
        }
    }

    return ans;
}

int main()
{
    vector<int> root = {1, -1};
    int k = 1;
    vector<int> ans = maxSlidingWindow(root, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}