// ? 307. Range Sum Query - Mutable
// ? https://leetcode.com/problems/range-sum-query-mutable/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class NumArrayTLE
{
    vector<int> current;
    vector<int> prefix_sum;

public:
    NumArrayTLE(vector<int> &nums)
    {
        current = nums;
        prefix_sum.reserve(nums.size());

        prefix_sum.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            prefix_sum.push_back(prefix_sum[i - 1] + nums[i]);
        }
    }

    void update(int index, int val)
    {
        int diff = val - current[index];
        current[index] = val;
        for (int i = index; i < current.size(); i++)
        {
            prefix_sum[i] += diff;
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return prefix_sum[right];
        }

        return prefix_sum[right] - prefix_sum[left - 1];
    }
};

class NumArray
{
    vector<int> current;
    int sum = 0;

public:
    NumArray(vector<int> &nums)
    {
        current = nums;
        for (auto const &i : nums)
        {
            sum += i;
        }
    }

    void update(int index, int val)
    {
        sum -= current[index];
        current[index] = val;
        sum += val;
    }

    int sumRange(int left, int right)
    {
        int result = sum;

        while (left--)
        {
            result -= current[left];
        }

        while (++right < current.size())
        {
            result -= current[right];
        }

        return result;
    }
};

// TODO: Could have used BTree

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
}