// ? 326. Power of Three
// ? https://leetcode.com/problems/power-of-three/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// recursion was not allowed
bool isPowerOfThree(int n)
{
    log10(n);
    if (n <= 0)
    {
        return false;
    }

    if (n == 1)
    {
        return true;
    }

    if (n % 3 == 0)
    {
        return isPowerOfThree(n / 3);
    }

    return false;
}

bool betterSOl(int n)
{
    if (n <= 0)
    {
        return false;
    }

    double l = log10(n) / log10(3);
    int i = l;

    return l - i == 0;
}

// This is too genius of a solution its -> 3^19 = 1162261467
bool tooGeniusMethod(int n)
{
    return n > 0 && 1162261467 % n == 0;
}

int main()
{
    cout << isPowerOfThree(27);
}