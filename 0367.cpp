// ? 367. Valid Perfect Square
// ? https://leetcode.com/problems/valid-perfect-square/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isPerfectSquare(int num)
{
    int start = 1;
    int end = num;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        if (num == mid * mid)
        {
            return true;
        }

        if (num > mid * mid)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}

int main()
{
}