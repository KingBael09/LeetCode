// ? 88. Merge Sorted Array
// ? https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void mergeSlow(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int initSize = nums1.size();
    for (int i = m; i < initSize; i++)
    {
        nums1[i] = nums2[i - m];
    }

    sort(nums1.begin(), nums1.end());
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int init1 = m - 1;
    int init2 = n - 1;
    int fin = m + n - 1;

    while (init1 >= 0 && init2 >= 0)
    {
        if (nums1[init1] > nums2[init2])
        {
            nums1[fin] = nums1[init1];
            init1--;
            fin--;
        }
        else
        {
            nums1[fin] = nums2[init2];
            fin--;
            init2--;
        }
    }

    while (init2 >= 0)
    {
        nums1[fin] = nums2[init2];
        init2--;
        fin--;
    }
}

void mergeRefactored(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int init1 = m - 1, init2 = n - 1, fin = m + n - 1;

    while (init1 >= 0 && init2 >= 0)
    {
        if (nums1[init1] > nums2[init2])
        {
            nums1[fin--] = nums1[init1--];
        }
        else
        {
            nums1[fin--] = nums2[init2--];
        }
    }

    while (init2 >= 0)
    {
        nums1[fin--] = nums2[init2--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    mergeSlow(nums1, m, nums2, n);

    for (auto i : nums1)
    {
        cout << i << " ";
    }
}
