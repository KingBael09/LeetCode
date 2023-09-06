#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int badSol(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (auto i : nums)
    {
        m[i]++;
    }

    for (auto i : m)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }

    return 0;
}

/**
 * ### Method: XOR
 * The idea here is that xor for same numbers is 0
 * only if the number is not repeated it will be returned
 */
int singleNumber(vector<int> &nums)
{
    int xorr = 0;

    for (auto i : nums)
    {
        xorr ^= i;
    }

    return xorr;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2, 3, 3};
    cout << singleNumber(nums);
}
