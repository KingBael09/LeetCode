// ? 525. Contiguous Array
// ? https://leetcode.com/problems/contiguous-array/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> seen{{0, -1}};

    int sum = 0, maxLen = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] == 1 ? 1 : -1;
        if (seen.find(sum) != seen.end())
        {
            maxLen = max(maxLen, i - seen[sum]);
        }
        else
            seen[sum] = i;
    }
    return maxLen;
}

int main()
{
    vector<int> s{0, 0, 1, 0, 0, 0, 1, 1};
    cout << findMaxLength(s);
}