// ? 4. Median of Two Sorted Arrays
// ? https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Very bad solution
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());

    sort(nums1.begin(), nums1.end());

    int size = nums1.size();

    if (size % 2 == 0)
    {
        return (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;
    }
    else
    {
        return nums1[size / 2];
    }

    return size % 2 ? nums1[size / 2] : (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;
}

// TODO: Write a better solution

double findMedianSortedArraysMaybeFaster(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());

    sort(nums1.begin(), nums1.end());

    int size = nums1.size();

    return size % 2 ? nums1[size / 2] : (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays(nums1, nums2);
}
