// ? 231. Power of Two
// ? https://leetcode.com/problems/power-of-two/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isPowerOfTwo(int n)
{
    if (n < 1)
    {
        return false;
    }

    auto x = log2(n);
    if (modf(x, &x) == 0)
    {
        return true;
    }

    return false;
}

bool isPowerOfTwoBetter(int n)
{
    while (n)
    {
        int it = n >> 1; // perform right shift
        if (n & 1)       // check if last bit is 1
        {
            if (!it)
            {
                return true;
            }
            break;
        }
        n = it;
    }

    return false;
}

int main()
{
    cout << isPowerOfTwoBetter(16);
}