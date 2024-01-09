// ? 852. Peak Index in a Mountain Array
// ? https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Not a very good method -> O(n)
int bruteForcePeak(vector<int> &arr)
{
    int maxVal = -INT_MAX;
    int maxIndex = 0;
    int len = arr.size();

    for (int i = 0; i < len; i++)
    {
        if (maxVal < arr[i])
        {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

// O(log(n))
int peakIndexMountain(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (arr[mid + 1] > arr[mid])
        {
            start = mid + 1;
        }
        else if (arr[mid + 1] < arr[mid])
        {
            end = mid;
        }
    }

    return start;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << peakIndexMountain(nums);
}
