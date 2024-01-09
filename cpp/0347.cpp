// ? 347. Top K Frequent Elements
// ? https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> m;
    priority_queue<pair<int, int>> pq;
    for (int i : nums)
    {
        m[i]++;
    }

    for (auto i : m)
    {
        pq.push({i.second, i.first});
    }

    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// TODO: There must be a better method

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3};
    for (auto i : topKFrequent(nums, 2))
    {
        cout << i << " ";
    }
}
