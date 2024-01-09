// ? 704. Binary Search
// ? https://leetcode.com/problems/binary-search/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }

    if (target < nums[mid])
    {
        return binarySearch(nums, start, mid - 1, target);
    }

    if (target > nums[mid])
    {
        return binarySearch(nums, mid + 1, end, target);
    }

    return -1;
}

int recursiveSearch(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int iterativeSearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (target < nums[mid])
        {
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
    }

    return -1;
}

// This isn't actually bruteforce
int bruteForce(vector<int> &nums, int target)
{
    auto it = find(nums.begin(), nums.end(), target);

    if (it != nums.end())
    {
        return it - nums.begin();
    }
    else
    {
        return -1;
    }
}

// TODO: Is there no way which is more memory efficient?

int main()
{
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << recursiveSearch(nums, target);
    // cout << bruteForce(nums, target);
}
