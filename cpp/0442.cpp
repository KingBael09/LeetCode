// ? 442. Find All Duplicates in an Array
// ? https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This doesn't use constant space
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);

    vector<int> another;

    for (auto i : nums)
    {
        if (ans[i - 1] == 0)
        {
            ans[i - 1] = i;
        }
        else
        {
            another.push_back(i);
        }
    }

    return another;
}

vector<int> findDuplicatesBetter(vector<int> &nums)
{
    vector<int> ans;
    for (int i : nums)
    {
        int idx = abs(i);
        if (nums[idx - 1] > 0)
        {
            nums[idx - 1] *= -1;
        }
        else if (nums[idx - 1] < 0)
        {
            ans.push_back(idx);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};

    for (auto i : findDuplicates(nums))
    {
        cout << i << " ";
    }
}