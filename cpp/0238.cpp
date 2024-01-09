// ? 238. Product of Array Except Self
// ? https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> dumbSolution(vector<int> &nums)
{
    vector<int> res(nums.size());

    for (auto i = 0; i < nums.size(); i++)
    {
        auto prod = 1;
        for (auto j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                prod *= nums[j];
            }
        }
        res[i] = prod;
    }

    return res;
}

// used more space
vector<int> productExceptSelf(vector<int> &nums)
{
    int size = nums.size();

    vector<int> leftProd(size, 1);
    vector<int> rightProd(size, 1);

    for (int i = 1; i < size; i++)
    {
        leftProd[i] = leftProd[i - 1] * nums[i - 1];
    }

    for (int i = size - 2; i >= 0; i--)
    {
        rightProd[i] = rightProd[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < size; i++)
    {
        nums[i] = leftProd[i] * rightProd[i];
    }

    return nums;
}

vector<int> productExceptSelfEfficient(vector<int> &nums)
{
    int size = nums.size();

    vector<int> res(size, 1);
    int curr = 1;

    for (int i = 0; i < size; i++)
    {
        res[i] *= curr;
        curr *= nums[i];
    }
    curr = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        res[i] *= curr;
        curr *= nums[i];
    }

    return res;
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    for (auto i : productExceptSelfEfficient(v))
    {
        cout << i << " ";
    }
}
