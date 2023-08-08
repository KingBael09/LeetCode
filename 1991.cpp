// ? 1991. Find the Middle Index in Array
// ? https://leetcode.com/problems/find-the-middle-index-in-array/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMiddleIndex(vector<int> nums)
{
    int len = nums.size();
    int end = 0;

    int sum = 0;

    while (end < len)
    {

        sum += nums[end];

        int remSum = 0;

        for (int i = end + 1; i < len; i++)
        {
            remSum += nums[i];
        }

        if (remSum == sum - nums[end])
        {
            return end;
        }

        end++;
    }

    return -1;
}

int main()
{
    vector<int> nums{4, 0};

    int ans = getMiddleIndex(nums);

    cout << ans << endl;
}