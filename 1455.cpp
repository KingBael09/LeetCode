// ? 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// ? https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int isPrefixOfWord(string sentence, string searchWord)
{
    stringstream ss(sentence);

    int count = 0;

    string word;

    while (ss >> word)
    {
        count++;
        word.resize(searchWord.size());

        if (word == searchWord)
        {
            return count;
        }
    }

    return -1;
}