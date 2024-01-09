// ? 128. Longest Consecutive Sequence
// ? https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This is a bad solution because it solves it in O(nlogn) time
int longestConsecutive(vector<int> &nums)
{
    int len = nums.size();

    if (len == 0)
    {
        return 0;
    }

    sort(nums.begin(), nums.end());
    auto it = unique(nums.begin(), nums.end());

    nums.resize(distance(nums.begin(), it));

    int mx = 0;

    int end = 0;
    int count = 1;

    for (int i = 0; i < len - 1; i++)
    {
        if (nums[i + 1] - nums[i] == 1)
        {
            count++;
        }
        else
        {
            mx = max(count, mx);
            count = 1;
        }
    }

    return max(mx, count);
}

// This is maybe better but i am not sure about the time complexity being O(n)
int longestConsecutiveBetter(vector<int> &nums)
{
    int len = nums.size();

    if (len == 0)
    {
        return 0;
    }

    map<int, int> m;

    for (auto i : nums)
    {
        m[i]++;
    }

    int mx = 0;
    int prev = INT_MIN; // placeholder
    int count = 1;

    for (auto i : m)
    {
        if (prev != INT_MIN)
        {
            if (i.first - prev == 1)
            {
                count++;
            }
            else
            {
                mx = max(mx, count);
                count = 1;
            }
        }
        prev = i.first;
    }

    return max(mx, count);
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    // cout << longestConsecutive(nums);
    cout << longestConsecutiveBetter(nums);
}
