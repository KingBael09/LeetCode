// ? 33. Search in Rotated Sorted Array
// ? https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// O(N) Solution
int search(vector<int> &nums, int target)
{
    int res = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            res = i;
        }
    }

    return res;
}

// TODO: O(log(N)) solution incomplete
int searchFaster(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        // Left is sorted
        else if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums = {1, 3};
    // cout << search(nums, 0);
    cout << searchFaster(nums, 1);
}