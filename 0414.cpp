// ? 414. Third Maximum Number
// ? https://leetcode.com/problems/third-maximum-number/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getThirdMax(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    auto it = unique(nums.begin(), nums.end());

    nums.resize(distance(nums.begin(), it));

    int len = nums.size();

    if (len < 3)
    {
        return nums.back();
    }

    return nums[len - 3];
}

int main()
{
    vector<int> list{1, 2, 2, 5, 3, 5};
    int res = getThirdMax(list);

    cout << res;
}