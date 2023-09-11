// ? 326. Power of Three
// ? https://leetcode.com/problems/power-of-three/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isPowerOfThree(int n)
{
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

int main()
{
    cout << isPowerOfThree(27);
}