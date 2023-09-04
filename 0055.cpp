// ? 55. Jump Game
// ? https://leetcode.com/problems/jump-game/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool canJump(vector<int> &nums)
{
    int len = nums.size();

    int end = 0;

    int start = 0;

    while (start < len)
    {

        if (start > end)
        {
            return false;
        }

        end = max(end, start + nums[start]);

        start++;
    }

    return true;
}

// Code can be reduced to a for loop
bool canJump2(vector<int> &nums)
{
    int end = 0;
    for (int start = 0; start < nums.size(); start++)
    {
        if (start > end)
        {
            return false;
        }

        end = max(end, start + nums[start]);
    }

    return true;
}

int main()
{
    vector<int> nums{2, 3, 1, 1, 4};

    if (canJump(nums))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}