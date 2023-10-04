// ? 189. Rotate Array
// ? https://leetcode.com/problems/rotate-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    if (nums.size() < 2)
    {
        return;
    }

    if (nums.size() < k)
    {
        k = k % nums.size();
    }

    vector<int> newNum;

    for (int i = nums.size() - k; i < nums.size(); i++)
    {
        newNum.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size() - k; i++)
    {
        newNum.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = newNum[i];
    }

    return;
}

void rotateBetter(vector<int> &nums, int k)
{
    int size = nums.size();

    k %= size;
    size -= k;
    reverse(nums.begin(), nums.begin() + size);

    reverse(nums.begin() + size, nums.end());

    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};

    rotateBetter(nums, 3);
}