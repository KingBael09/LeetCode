// ? 215. Kth Largest Element in an Array
// ? https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// This method is no good because sorting is used
int findKthLargest(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    return nums[nums.size() - k];
}

// TODO: Learn priority queue
int findKthLargestWithoutSorting(vector<int> &nums, int k)
{
    priority_queue<int> q(nums.begin(), nums.end());
}

int main()
{
    vector<int> list{3, 2, 3, 1, 2, 4, 5, 5, 6};

    int k = 4;

    int ans = findKthLargest(list, k);

    cout << ans;
}