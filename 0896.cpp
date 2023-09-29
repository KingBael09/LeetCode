// ? 896. Monotonic Array
// ? https://leetcode.com/problems/monotonic-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This is such a bad solution
bool isMonotonic(vector<int> &nums)
{
    if (nums.size() < 3)
    {
        return true;
    }

    int inc = 0;
    int dec = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            inc++;
        }
        else if (nums[i] > nums[i + 1])
        {
            dec++;
        }
    }

    return inc == 0 && dec != 0 || inc != 0 && dec == 0 || inc == 0 && dec == 0;
}

bool isMonotonicBetter(vector<int> &nums)
{
    int size = nums.size();

    if (size < 3)
    {
        return true;
    }

    bool inc = true;
    bool dec = true;

    for (int i = 0; i < size - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            inc = false;
        }
        else if (nums[i] < nums[i + 1])
        {
            dec = false;
        }
        if (!inc && !dec)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> nums = {1, 3, 2, 4};
    cout << isMonotonic(nums);
}
