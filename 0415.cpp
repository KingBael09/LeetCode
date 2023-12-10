// ? 415. Add Strings
// ? https://leetcode.com/problems/add-strings/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string addStrings(string num1, string num2)
{
    int carry = 0;
    int l1 = num1.size() - 1;
    int l2 = num2.size() - 1;

    string ans = "";

    while (l1 >= 0 || l2 >= 0 || carry > 0)
    {
        if (l1 >= 0)
        {
            carry += num1[l1--] - '0';
        }

        if (l2 >= 0)
        {
            carry += num2[l2--] - '0';
        }

        ans += char(carry % 10 + '0');
        carry /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
}