// ? 2442. Count Number of Distinct Integers After Reverse Operations
// ? https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int countDistinctIntegers(vector<int> &nums)
{
    vector<int> v(nums);
    for (auto i : nums)
    {
        int num = 0;
        while (i > 0)
        {
            num = num * 10 + i % 10;
            i /= 10;
        }
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());

    v.resize(distance(v.begin(), it));

    return v.size();
}

int countDistinctIntegersBetter(vector<int> &nums)
{
    unordered_set<int> s;

    for (auto i : nums)
    {
        s.insert(i);
        int num = 0;
        while (i > 0)
        {
            num = num * 10 + i % 10;
            i /= 10;
        }
        s.insert(num);
    }

    return s.size();
}

// TODO: See methods using bitset

int main()
{
    vector<int> nums{1, 13, 10, 12, 31};
    cout << countDistinctIntegers(nums);
}