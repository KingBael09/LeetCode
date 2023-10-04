// ? 164. Maximum Gap
// ? https://leetcode.com/problems/maximum-gap/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int ifIRuledTheWorld(vector<int> &nums)
{
    int sz = nums.size();

    if (sz < 2)
    {
        return 0;
    }

    int gap = 0;
    sort(nums.begin(), nums.end());

    for (int i = 1; i < sz; i++)
    {
        gap = max(gap, nums[i] - nums[i - 1]);
    }

    return gap;
}

// This gives TLE
int maximumGapLinearButSlow(vector<int> &nums)
{
    int sz = nums.size();

    if (sz < 2)
    {
        return 0;
    }

    int mx = nums[0];

    for (int i : nums)
    {
        mx = max(mx, i);
    }

    vector<bool> m(mx + 1, false);

    for (int i : nums)
    {
        m[i] = true;
    }
    int diff = INT_MIN;
    int start = 0, end = 0;

    // Start is at true

    while (!m[start])
    {
        start++;
    }
    end = start;

    while (end < m.size())
    {
        if (m[end])
        {
            diff = max(diff, end - start);
            start = end;
        }
        end++;
    }

    return diff;
}

/**
 * ### Algorithm: Bucket Sort
 */
int maximumGap(vector<int> &nums)
{
    int sz = nums.size();
    if (sz < 2)
    {
        return 0;
    }

    if (sz == 2)
    {
        return abs(nums.front() - nums.back());
    }

    int mn = nums[0];
    int mx = nums[0];

    for (auto i : nums)
    {
        mn = min(mn, i);
        mx = max(mx, i);
    }

    int gap = ceil(float(mx - mn) / (sz - 1));
    if (gap == 0)
    {
        return 0; // all elements are same
    }

    vector<int> minBucket(sz, INT_MAX);
    vector<int> maxBucket(sz, INT_MIN);

    for (auto i : nums)
    {
        int bucket = (i - mn) / gap;

        maxBucket[bucket] = max(maxBucket[bucket], i);
        minBucket[bucket] = min(minBucket[bucket], i);
    }

    int ans = gap;

    int prevMax = maxBucket[0];

    for (int i = 1; i < sz; i++)
    {
        if (minBucket[i] == INT_MAX)
        {
            continue;
        }

        ans = max(ans, minBucket[i] - prevMax);
        prevMax = maxBucket[i];
    }

    return ans;
}

int main()
{
    vector<int> v = {3, 6, 9, 1};
    cout << maximumGap(v);
}