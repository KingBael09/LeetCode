// ? 69. Sqrt(x)
// ? https://leetcode.com/problems/sqrtx/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int mySqrt(int x)
{
    if (x == 0)
    {
        return x;
    }

    auto first = 1, last = x;

    while (first <= last)
    {
        auto mid = first + (last - first) / 2;

        if (mid == x / mid)
        {
            return mid;
        }

        if (mid > x / mid)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    return last;
}

int main()
{
}