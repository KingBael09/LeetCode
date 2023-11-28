// ? 278. First Bad Version
// ? https://leetcode.com/problems/first-bad-version/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isBadVersion(int version)
{
    // hypothetical function to check if a version is bad
}

int firstBadVersionDumb(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (isBadVersion(i))
        {
            return i;
        }
    }

    return -1;
}

int firstBadVersion(int n)
{

    int left = 0;
    int right = n;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid > 0 && isBadVersion(mid) && !isBadVersion(mid - 1))
        {
            return mid;
        }

        if (isBadVersion(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
}