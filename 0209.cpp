// ? https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMinSubarraySum(int target, vector<int> nums)
{
    int len = nums.size();

    int minLen = 0;
    int start = 0;
    int end = 0;
    int curSum = 0;

    while (end < len)
    {

        curSum += nums[end];

        while (curSum >= target)
        {
            if (minLen == 0)
            {
                minLen = end - start + 1;
            }

            minLen = min(minLen, end - start + 1);
            curSum -= nums[start];
            start++;
        }

        end++;
    }

    return minLen;
}

int betterGetMinSubarraySum(int target, vector<int> nums)
{
    int len = nums.size();

    int minLen = INT_MAX;
    int start = 0;
    int end = 0;
    int curSum = 0;

    while (end < len)
    {

        curSum += nums[end];

        while (curSum >= target)
        {
            minLen = min(minLen, end - start + 1);
            curSum -= nums[start];
            start++;
        }

        end++;
    }

    if (minLen == INT_MAX)
    {
        return 0;
    }

    return minLen;
}

int main()
{

    vector<int> nums{2, 3, 1, 2, 4, 3};

    int target = 7;

    int len = getMinSubarraySum(target, nums);

    cout << endl
         << len;
}