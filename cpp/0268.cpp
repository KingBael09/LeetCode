// ? 268. Missing Number
// ? https://leetcode.com/problems/missing-number/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int missingNumberNaive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }

    return nums.size();
}

int missingNumber(vector<int> &nums)
{
    int n = nums.size();

    auto total = n * (n + 1) / 2;
    auto sum = 0;

    for (auto &i : nums)
    {
        sum += i;
    }
    return total - sum;
}

int main()
{
}