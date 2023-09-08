// ? 283. Move Zeroes
// ? https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int pos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[pos] = nums[i];
            pos++;
        }
    }

    for (pos; pos < nums.size(); pos++)
    {
        nums[pos] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (auto i : nums)
    {
        cout << i << " ";
    }
}
