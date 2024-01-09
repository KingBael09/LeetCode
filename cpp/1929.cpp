// ? 1929. Concatenation of Array
// ? https://leetcode.com/problems/concatenation-of-array/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    int sz = nums.size();
    for (int i = 0; i < sz; i++)
    {
        nums.push_back(nums[i]);
    }

    return nums;
}

int main()
{
    // I don't wanna write driver code
}