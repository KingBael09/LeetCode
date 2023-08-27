// ? 58. Length of Last Word
// ? https://leetcode.com/problems/length-of-last-word/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    int count = 0, actItr = s.length() - 1;

    while (s[actItr] == ' ')
    {
        actItr--;
    }

    while (actItr >= 0 && s[actItr] != ' ')
    {
        count++;
        actItr--;
    }

    return count;
}

int lengthOfLastWordButFaster(string s)
{
    int len = s.length() - 1;

    int curr = 0;
    bool wordStarted = false;

    // go from right to left if actual word startd then raise flag and terminate if word ends with flag true
    for (int i = len; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            wordStarted = true;
            curr++;
        }

        if (wordStarted && s[i] == ' ')
        {
            break;
        }
    }

    return curr;
}

int main()
{
    string s = "day ";

    cout << lengthOfLastWord(s);
}