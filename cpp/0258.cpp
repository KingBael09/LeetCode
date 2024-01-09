// ? 258. Add Digits
// ? https://leetcode.com/problems/add-digits/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int addDigits(int num)
{
    if (num < 10)
    {
        return num;
    }

    int sum = 0;

    while (num)
    {
        sum += num % 10;
        num /= 10;
    }

    return addDigits(sum);
}

int main()
{
}