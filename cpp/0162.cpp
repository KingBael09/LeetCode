// ? 162. Find Peak Element
// ? https://leetcode.com/problems/find-peak-element/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] > nums[mid + 1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

int findPeakElementBuiltIn(vector<int> &nums)
{
    return max_element(nums.begin(), nums.end()) - nums.begin();
}

int main()
{
}