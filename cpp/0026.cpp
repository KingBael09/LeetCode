// ? 26. Remove Duplicates from Sorted Array
// ? https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    set<int> s(nums.begin(), nums.end());
    nums.assign(s.begin(), s.end());
    return s.size();
}

int removeDuplicatesEfficient(vector<int> &nums)
{
    int len = nums.size() - 1;
    int k = 1;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[k] = nums[i + 1];
            k++;
        }
    }
    return k;
}

int main()
{
    vector<int> v{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // cout << removeDuplicates(v);
    cout << removeDuplicatesEfficient(v);
}