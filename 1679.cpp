// ? 1679. Max Number of K-Sum Pairs
// ? https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int start = 0;
    int end = nums.size() - 1;
    int opr = 0;
    while (start < end)
    {
        int curSum = nums[start] + nums[end];
        if (curSum > k)
        {
            end--;
        }
        else if (curSum < k)
        {
            start++;
        }
        else if (curSum == k)
        {
            opr++;
            start++;
            end--;
        }
    }

    return opr;
}

int main()
{
    vector<int> list{1, 2, 3, 4};
    int target = 5;

    int ans = maxOperations(list, target);

    cout << ans << endl;
}

// TODO: This could be optimized a bit ig