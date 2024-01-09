// ? 53. Maximum Subarray
// ? https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/**
 * ### Algorithm: Kadane’s Algorithm
 * This algorithm maintains a max value which resets when negative value is encountered.
 */
int maxSubArray(vector<int> &nums)
{
    int max_sum = nums[0], sum = 0;

    for (auto i : nums)
    {
        sum += i;
        max_sum = max(max_sum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max_sum;
}

int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums);
}