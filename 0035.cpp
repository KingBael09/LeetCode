// ? 35. Search Insert Position
// ? https://leetcode.com/problems/search-insert-position/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int mid;
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (nums[mid] < target)
    {
        return mid + 1;
    }
    return mid;
}

int otherMethod(vector<int> &nums, int target)
{
    if (target < nums.front())
    {
        return 0;
    }
    int left = 0, right = nums.size() - 1, mid = (right + left) / 2;

    while (right >= left)
    {
        if (target == nums[mid])
        {
            return mid;
        }

        if (target < nums[mid])
        {
            right = mid - 1;
            mid = (right + left) / 2;
        }
        else
        {
            left = mid + 1;
            mid = (right + left) / 2;
        }
    }

    return mid + 1;
}

int main()
{
}