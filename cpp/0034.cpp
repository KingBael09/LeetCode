// ? 34. Find First and Last Position of Element in Sorted Array
// ? https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> searchRangeLinear(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 1)
    {
        if (nums[0] == target)
        {
            return {0, 0};
        }
        else
            return {-1, -1};
    }

    int start = -1;
    int end = -1;

    for (int i = 0; i < len; i++)
    {
        if (nums[i] == target)
        {
            if (start == -1)
            {
                start = i;
            }
            if (i + 1 < len && nums[i + 1] != target)
            {
                end = i;
            }
            if (i + 1 == len)
            {
                end = i;
            }
        }
    }

    return {start, end};
}

int getMinPos(vector<int> &nums, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

vector<int> searchRangeBinary(vector<int> &nums, int target)
{
    int start = getMinPos(nums, 0, nums.size() - 1, target);
    int end = getMinPos(nums, 0, nums.size() - 1, target + 1) - 1;

    if (start < nums.size() && nums[start] == target)
    {
        return {start, end};
    }

    return {-1, -1};
}

int main()
{
    vector<int> ds{5, 7, 7, 8, 8, 10};
    int target = 8;
    // vector<int> ds{1, 2, 2, 3};
    // int target = 2;

    // for (auto i : searchRangeLinear(ds, target))
    // {
    //     cout << i << " ";
    // }
    for (auto i : searchRangeBinary(ds, target))
    {
        cout << i << " ";
    }
}