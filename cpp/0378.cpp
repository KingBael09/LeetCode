// ? 378. Kth Smallest Element in a Sorted Matrix
// ? https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int kthSmallestDumb(vector<vector<int>> &matrix, int k)
{
    vector<int> nums;

    for (auto row : matrix)
    {
        for (auto ele : row)
        {
            nums.push_back(ele);
        }
    }

    sort(nums.begin(), nums.end());

    return nums[k - 1];
}

// Binary Search in Matrix

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int start = matrix.front().front();
    int end = matrix.back().back();

    while (start <= end)
    {
        int mid = (end + start) / 2;
        int cnt = 0;

        for (auto &i : matrix)
        {
            cnt += upper_bound(i.begin(), i.end(), mid) - i.begin();
        }

        if (cnt < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}

// Raw

int kthSmallestRaw(vector<vector<int>> &matrix, int k)
{
    int start = matrix.front().front();
    int end = matrix.back().back();
    int mid, ct = 0;

    while (start <= end)
    {
        ct = 0;
        mid = start + (end - start) / 2;

        for (auto &i : matrix)
        {
            for (auto &j : i)
            {
                if (j <= mid)
                {
                    ct++;
                }
                // OR
                // if (j > mid)
                // {
                //     break;
                // }

                // ct++;
            }
        }

        if (ct < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}

int main()
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;

    cout << kthSmallestDumb(matrix, k);
}