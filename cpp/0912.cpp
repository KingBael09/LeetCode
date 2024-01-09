// ? 912. Sort an Array
// ? https://leetcode.com/problems/sort-an-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This is basically cheating
vector<int> getSortedList(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    return nums;
}

vector<int> getSortedWithoutBuiltIn(vector<int> nums)
{
    int len = nums.size() - 1;
    priority_queue<int> pq;

    for (auto i : nums)
    {
        pq.push(i);
    }

    for (int i = len; i >= 0; i--)
    {
        nums[i] = pq.top();
        pq.pop();
    }

    return nums;
}

// TODO: Many Other methods remaining

int main()
{
    vector<int> v{5, 1, 1, 2, 0, 0};

    // vector<int> z = getSortedList(v);

    vector<int> z = getSortedWithoutBuiltIn(v);
    for (auto i : z)
    {
        cout << i << " ";
    }
}