// ? 338. Counting Bits
// ? https://leetcode.com/problems/counting-bits/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}

int main()
{
}