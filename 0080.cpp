// ? 80. Remove Duplicates from Sorted Array II
// ? https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Here i delete the unwanted element
int removeDuplicates(vector<int> &nums)
{
    for (int i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i - 1] == nums[i] && nums[i] == nums[i + 1])
        {
            nums.erase(nums.begin() + i + 1);
            i--;
        }
    }
    return nums.size();
}

// This doesn't delete the unwanted element
int removeDuplicateWithoutRemoving(vector<int> &nums)
{
    int slow = 0;

    for (int x : nums)
    {
        if (slow < 2 || x != nums[slow - 2])
        {
            nums[slow++] = x;
        }
    }

    return slow;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicateWithoutRemoving(nums);
}