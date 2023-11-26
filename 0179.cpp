// ? 179. Largest Number
// ? https://leetcode.com/problems/largest-number/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

static bool compare(string &a, string &b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> &nums)
{
    string ans = "";

    vector<string> strs;

    for (auto &i : nums)
    {
        strs.push_back(to_string(i));
    }

    sort(strs.begin(), strs.end(), compare);

    for (auto &i : strs)
    {
        ans += i;
    }

    // For test case [0,0] -> "00" -> "0"
    if (ans.front() == '0')
    {
        return "0";
    }

    return ans;
}

int main()
{
    vector<int> nums{3, 30, 34, 5, 9};
    cout << largestNumber(nums);
}