// ? 125. Valid Palindrome
// ? https://leetcode.com/problems/valid-palindrome/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// TODO: This works locally but leetcode refuses to run it -> gotta think of a work around
bool itWorksButLeetCodeRefusesToRunIt(string s)
{

    for (int i = 0; i < s.size(); i++)
    {

        if (!isalnum(s[i]))
        {
            s.erase(i--, 1);
        }

        s[i] = tolower(s[i]);
    }

    cout << s << endl;

    int start = 0;
    int end = s.size() - 1;

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

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (!isalnum(s[start]))
        {
            start++;
            continue;
        }
        if (!isalnum(s[end]))
        {
            end--;
            continue;
        }

        if (tolower(s[start]) != tolower(s[end]))
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main()
{
    if (isPalindrome("A man, a plan, a canal: Panama"))
    {
        cout << "Is Palindrome";
    }
    else
    {
        cout << "Is not Palindrome";
    }
}