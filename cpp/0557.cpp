// ? 557. Reverse Words in a String III
// ? https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string reverseWords(string s)
{
    stringstream ss(s);

    string word;
    s.clear();
    while (ss >> word)
    {
        reverse(word.begin(), word.end());
        s += word + " ";
    }
    s.pop_back();

    return s;
}

int main()
{
    string s = "Let's take LeetCode contest";

    cout << reverseWords(s);
}