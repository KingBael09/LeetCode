// ? 287. Find the Duplicate Number
// ? https://leetcode.com/problems/find-the-duplicate-number/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This does modify the array
int findDuplicateModifiy(vector<int> &nums)
{
    for (int i : nums)
    {
        int idx = abs(i);

        if (nums[idx] < 0)
        {
            return idx;
        }

        nums[idx] *= -1;
    }

    return -1;
}

// This is basically tortoise and hare algorithg
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        fast = nums[nums[fast]]; // fast = fast->next->next;
        slow = nums[slow];       // slow = slow->next;
    } while (fast != slow);

    fast = nums[0];

    while (fast != slow)
    {
        fast = nums[fast]; // fast = fast->next;
        slow = nums[slow]; // slow = slow->next;
    }

    return slow;
}

int main()
{
    vector<int> nums = {0, 3, 1, 3, 4, 2};
    cout << findDuplicate(nums);
}
