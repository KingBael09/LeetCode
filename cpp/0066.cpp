// ? 66. Plus One
// ? https://leetcode.com/problems/plus-one/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        digits[i]++;

        if (digits[i] != 10)
        {
            return digits;
        }

        digits[i] = 0;
    }

    vector<int> ans{1};
    ans.insert(ans.end(), digits.begin(), digits.end());
    return ans;
}

int main()
{
}