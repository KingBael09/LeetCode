// ? 172. Factorial Trailing Zeroes
// ? https://leetcode.com/problems/factorial-trailing-zeroes/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int trailingZeroes(int n)
{
    int count = 0;
    while (n)
    {
        count += n / 5;
        n /= 5;
    }

    return count;
}

int main()
{
    cout << trailingZeroes(10);
}