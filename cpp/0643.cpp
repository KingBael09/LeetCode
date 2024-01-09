// ? 643. Maximum Average Subarray I
// ? https://leetcode.com/problems/maximum-average-subarray-i/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

double getMaxAverage(vector<int> &nums, int k)
{
    double maxVal = -INT_MAX;
    int start = 0;
    double windowSum = 0;
    for (int end = 0; end < nums.size(); end++)
    {
        windowSum += nums[end];

        if (end - start + 1 == k)
        {
            maxVal = max(maxVal, windowSum);
            windowSum -= nums[start];
            start++;
        }
    }

    return maxVal / k;
}

double getBetterMax(vector<int> &nums, int k)
{
    double window = 0;
    double ans = 0;

    // set window
    for (int i = 0; i < k; i++)
    {
        window += nums[i];
    }

    ans = window / k;

    for (int right = k; right < nums.size(); right++)
    {
        window += nums[right] - nums[right - k];
        ans = max(ans, window / k);
    }

    return ans;
}

int main()
{
    vector<int> v{1, 12, -5, -6, 50, 3};
    int k = 4;

    double another_value = getBetterMax(v, k);
    double value = getMaxAverage(v, k);
    cout << value;
}