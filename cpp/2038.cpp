// ? 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// ? https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool winnerOfGame(string colors)
{
    int ctA = 0, ctB = 0;

    for (int i = 1; i < colors.size() - 1; i++)
    {
        if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A')
        {
            ctA++;
        }
        if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B')
        {
            ctB++;
        }
    }

    return ctA >= ctB;
}

bool winnerOfGameSmaller(string colors)
{
    int ctA = 0, ctB = 0;

    for (int i = 1; i < colors.size() - 1; i++)
    {
        if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
        {
            ctA += colors[i] == 'A';
            ctB += colors[i] == 'B';
        }
    }

    return ctA > ctB;
}

int main()
{
    cout << winnerOfGame("AAABABB");
}