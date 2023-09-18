// ? 345. Reverse Vowels of a String
// ? https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isVowel(char &c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// This really is a bad method
string reverseVowelsBad(string s)
{
    stack<char> d;
    for (auto i : s)
    {
        if (isVowel(i))
        {
            d.push(i);
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[i]))
        {
            s[i] = d.top();
            d.pop();
        }
    }

    return s;
}

// this could be improved
string reverseVowels(string s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        while (start < end && !isVowel(s[start]))
        {
            start++;
        }
        while (start < end && !isVowel(s[end]))
        {
            end--;
        }

        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseVowelsbetter(string s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        bool leftVowel = isVowel(s[start]);
        bool rightVowel = isVowel(s[end]);

        if (leftVowel && rightVowel)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else
        {
            if (!leftVowel)
            {
                start++;
            }
            if (!rightVowel)
            {
                end--;
            }
        }
    }
}

int main()
{
}