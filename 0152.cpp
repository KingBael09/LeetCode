// ? 152. Maximum Product Subarray
// ? https://leetcode.com/problems/maximum-product-subarray/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

/**
 * ### Algorithm : Kanade's Algorithm
 */
int maxProd(vector<int> &nums)
{
    int max_prod = INT_MIN, prod = 1;

    for (auto i : nums)
    {
        prod *= i;
        max_prod = max(max_prod, prod);
        if (prod == 0)
        {
            prod = 1;
        }
    }

    prod = 1;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prod *= nums[i];
        max_prod = max(max_prod, prod);
        if (prod == 0)
        {
            prod = 1;
        }
    }

    return max_prod;
}

int maxProduct(vector<int> &nums)
{
    int n = nums.size() - 1;
    int pref = 1, suff = 1;
    int max_prod = INT_MIN;

    for (int i = 0; i <= n; i++)
    {
        if (pref == 0)
        {
            pref = 1;
        }
        if (suff == 0)
        {
            suff = 1;
        }

        pref *= nums[i];
        suff *= nums[n - i];
        max_prod = max(max_prod, max(suff, pref));
    }

    return max_prod;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProd(nums) << endl;
}
