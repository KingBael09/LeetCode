// ? 9. Palindrome Number
// ? https://leetcode.com/problems/palindrome-number/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// This is basically cheating and is memory inefficient
bool isPalindromeBadMethod(int x)
{
    if (x < 0)
    {
        return false;
    }

    string s = to_string(x);
    string rev = s;

    reverse(rev.begin(), rev.end());

    if (to_string(x) != rev)
    {
        return false;
    }

    return true;
}

bool isPalindromeBadMethodButFaster(int x)
{
    if (x < 0)
    {
        return false;
    }

    string s = to_string(x);

    int start = 0, end = s.length() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int reverse(int x)
{
    long reversed = 0;

    while (x)
    {
        reversed = reversed * 10 + (x % 10);
        x /= 10;
    }

    return reversed;
}

bool isPalindromeButFaster(int x)
{
    if (x >= 0)
    {
        return x == reverse(x);
    }

    return false;
}

bool isPalindromeButFasterAndNotRecursive(int x)
{
    if (x >= 0)
    {
        int orig = x;

        long reversed = 0;

        while (x)
        {
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }

        if (orig == reversed)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int x = 121;

    cout << isPalindromeButFaster(x);
}