// ? 169. Majority Element
// ? https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/**
 * ### Algorithm : Boyer-Moore Voting Algorithm
 *
 * - The idea here is to calculate the majority element by having the candidate and votes
 * - Initially we take the candidate at the top of list if we find the candidate we increment the vote, in case we find the other candidate we decrement the vote and if the vote reaches 0 we update the candidate
 *
 * In this, if the count reaches zero it means that before the current point there is no majority and
 * majority can be decied based on the incoming items from the list
 */
int majorityElement(vector<int> &nums)
{
    int count = 0;

    int ele = nums[0];

    for (auto i : nums)
    {
        if (count == 0)
        {
            ele = i;
            count++;
        }
        else
        {
            count += (ele == i) ? 1 : -1;
        }
    }

    return ele;
}

int main()
{
    vector<int> nums = {3, 2, 3};

    cout << majorityElement(nums);
}
