// ? 905. Sort Array By Parity
// ? https://leetcode.com/problems/sort-array-by-parity/description

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    int last = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            swap(nums[i], nums[last]);
            last++;
        }
    }

    return nums;
}

int main()
{
    // To alzy
}