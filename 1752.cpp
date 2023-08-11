
// ? 1752. Check if Array Is Sorted and Rotated
// ? https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool rotatedSortedArray(vector<int> &nums)
{
    int breakPoint = -1;
    int len = nums.size();

    for (int i = 0; i < len - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            breakPoint = i + 1;
            break;
        }
    }

    vector<int> secArr;

    if (breakPoint == -1)
    {
        return true;
    }

    for (int i = breakPoint; i < len; i++)
    {
        if (i != len - 1 && nums[i] > nums[i + 1])
        {
            return false;
        }

        secArr.push_back(nums[i]);
    }

    if (secArr.back() > nums[0])
    {
        return false;
    }

    return true;
}

bool betterRotatedSortedArray(vector<int> &nums)
{
    int len = nums.size() - 1;
    int breakPoint = -1;

    for (int i = 0; i < len; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            breakPoint = i + 1;
            break;
        }
    }

    if (breakPoint == -1)
    {
        return true;
    }

    for (int j = breakPoint; j < len; j++)
    {
        if (nums[j] > nums[j + 1])
        {
            return false;
        }
    }

    if (nums.back() > nums[0])
    {
        return false;
    }

    return true;
}

int main()
{
    vector<int> list{6, 10, 6};

    // bool ans = rotatedSortedArray(list);
    bool ans = betterRotatedSortedArray(list);

    if (ans == true)
    {
        cout << "true" << endl;
    }
    else
    {

        cout << "false" << endl;
    }
}

// j + 1 != len &&