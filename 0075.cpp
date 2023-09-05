// ? 75. Sort Colors
// ? https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This is a cheat solution
void cheatSolution(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}

// Also another dumb solution but it works
void sortColorsOK(vector<int> &nums)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for (auto i : nums)
    {
        if (i == 0)
        {
            zero++;
        }
        else if (i == 1)
        {
            one++;
        }
        else if (i == 2)
        {
            two++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (zero > 0)
        {
            nums[i] = 0;
            zero--;
        }
        else if (one > 0)
        {
            nums[i] = 1;
            one--;
        }
        else if (two > 0)
        {
            nums[i] = 2;
            two--;
        }
    }
}

// Algorithm: Dutch National Flag

/**
 * Dutch National Flag algorithm is used for three way partitoning of array which has three distinct values
 *
 *  Here three pointers are maintained -> low points to begning of array, high points to end of array,
 *  mid starts at begining and moves through it
 *
 *  The idea is that all 2's after high pointer, all the 1's between high and low pointer
 *  algorightm moves the mid pointer through the array comparing the values at each position comparing with 1.
 *  If the value is 0 the element is swapped with low ponter and low pointer and mid pointer are incremented.
 *  If the value is 2 the element is swapped with high pointer and high pointer is decremented.
 *  If the value is 1 the mid pointer is simply incremented.
 */
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {

            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    for (auto i : nums)
    {
        cout << i << " ";
    }
}
