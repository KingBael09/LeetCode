// ? 2149. Rearrange Array Elements by Sign
// ? https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    deque<int> positive;
    deque<int> negative;

    for (auto i : nums)
    {
        if (i < 0)
        {
            negative.push_back(i);
        }
        else
        {
            positive.push_back(i);
        }
    }

    bool isPositive = true;

    for (auto &i : nums)
    {
        if (isPositive)
        {
            i = positive.front();
            positive.pop_front();
        }
        else
        {
            i = negative.front();
            negative.pop_front();
        }

        isPositive = !isPositive;
    }

    return nums;
}

vector<int> rearrangeArrayOnePass(vector<int> &nums)
{
    int pos = 0, neg = 1;

    int sz = nums.size();

    vector<int> ans(sz);

    for (int i = 0; i < sz; i++)
    {
        if (nums[i] < 0)
        {
            ans[neg] = nums[i];
            neg += 2;
        }
        else
        {
            ans[pos] = nums[i];
            pos += 2;
        }
    }

    return ans;
}

int main()
{
}