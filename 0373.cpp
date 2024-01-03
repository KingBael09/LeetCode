// ? 373. Find K Pairs with Smallest Sums
// ? https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<vector<int>> kSmallestPairsTLE(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> ans;

    for (auto i : nums1)
    {
        for (auto j : nums2)
        {
            ans.push_back({i, j});
        }
    }

    sort(ans.begin(), ans.end(), [](auto a, auto b)
         { return a.front() + a.back() < b.front() + b.back(); });

    ans.resize(k);

    return ans;
}

// ---

typedef pair<int, int> idx_pair;

auto compare = [](const idx_pair &a, const idx_pair &b)
{ return a.first + a.second < b.first + b.second; };

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> ans;

    priority_queue<idx_pair, vector<idx_pair>, decltype(compare)> pq;

    for (auto i : nums1)
    {
        for (auto j : nums2)
        {
            if (pq.size() < k)
            {
                pq.push({i, j});
                continue;
            }

            auto [a, b] = pq.top();

            if (i + j >= a + b)
            {
                break;
            }

            pq.pop();
            pq.push({i, j});
        }
    }

    while (!pq.empty())
    {
        auto [i, j] = pq.top();
        pq.pop();
        ans.push_back({i, j});
    }

    return ans;
}

int main()
{
}