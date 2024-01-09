// ? 229. Majority Element II
// ? https://leetcode.com/problems/majority-element-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// TC: O(N) SC: O(N)
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size() / 3;
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i : nums)
    {
        mp[i]++;
    }

    for (auto i : mp)
    {
        if (i.second > n)
        {
            ans.push_back(i.first);
        }
    }

    return ans;
}

// TC: O(NlogN) SC: O(1)
vector<int> majorityElement2(vector<int> &nums)
{
    int sz = nums.size();
    if (sz == 1 || sz == 2 && nums.front() != nums.back())
    {
        return nums;
    }

    int majority = sz / 3;

    sort(nums.begin(), nums.end());

    unordered_set<int> s;
    vector<int> ans;

    int count = 1;

    for (int i = 1; i < sz; i++)
    {
        if (nums[i - 1] == nums[i])
        {
            count++;
            if (count > majority)
            {
                s.insert(nums[i]);
            }
        }
        else
        {
            count = 1;
        }
    }

    for (int it : s)
    {
        ans.push_back(it);
    }

    return ans;
}

// TC: O(N) SC: O(1)

/**
 * ### Algorithm : Boyer-Moore Voting Algorithm
 */
vector<int> majorityElement3(vector<int> &nums)
{
    int ct1 = 0, ct2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN; // there can only be two majority elements which are greatedn than n/3

    for (auto it : nums)
    {
        if (ele1 == it)
        {
            ct1++;
        }
        else if (ele2 == it)
        {
            ct2++;
        }
        else if (ct1 == 0)
        {
            ele1 = it;
            ct1 = 1;
        }
        else if (ct2 == 0)
        {
            ele2 = it;
            ct2 = 1;
        }
        else
        {
            ct1--;
            ct2--;
        }
    }

    vector<int> ans;
    int majority = nums.size() / 3;
    ct1 = ct2 = 0;
    for (auto it : nums)
    {
        if (it == ele1)
        {
            ct1++;
        }
        if (it == ele2)
        {
            ct2++;
        }
    }

    if (ct1 > majority)
    {
        ans.push_back(ele1);
    }
    if (ct2 > majority)
    {
        ans.push_back(ele2);
    }

    return ans;
}

int main()
{
}
