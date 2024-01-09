// ? 561. Array Partition
// ? https://leetcode.com/problems/array-partition/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int sum = 0;
    bool chk = true;

    for (auto &i : nums)
    {
        if (chk)
        {
            sum += i;
        }
        chk = !chk;
    }

    return sum;
}

int arrayPairSum2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int sum = 0;

    for (int i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }

    return sum;
}

int main()
{
}