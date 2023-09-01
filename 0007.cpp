// ? 7. Reverse Integer
// ? https://leetcode.com/problems/reverse-integer/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int reverse(int x)
{
    int rev = 0;

    while (x)
    {
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
        {
            return 0;
        }
        else
        {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
    }

    return rev;
}

int main()
{
    long i = -120;

    cout << reverse(i);
}