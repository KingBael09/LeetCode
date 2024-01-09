// ? 153. Find Minimum in Rotated Sorted Array
// ? https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int findMin(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    int ans = INT_MAX;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] < nums[end])
        {
            ans = min(ans, nums[start]);
            end = mid;
        }
        else
        {
            ans = min(ans, nums[mid]);
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
}