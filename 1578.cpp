// ? 1578. Minimum Time to Make Rope Colorful
// ? https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int minCost(string colors, vector<int> &neededTime)
{
    int prev = 0;
    int time = 0;

    for (int next = 1; next < colors.size(); next++)
    {
        if (colors[prev] != colors[next])
        {
            prev = next;
            continue;
        }

        time += min(neededTime[prev], neededTime[next]);

        if (neededTime[prev] < neededTime[next])
        {
            prev = next;
            // match prev only if we select previous
        }
    }

    return time;
}

int minCostBetter(string colors, vector<int> &neededTime)
{
    int prev = 0;
    int time = 0;

    for (int next = 1; next < colors.size(); next++)
    {
        if (colors[prev] != colors[next])
        {
            prev = next;
            continue;
        }

        int increment = min(neededTime[prev], neededTime[next]);

        if (neededTime[prev] == increment)
        {
            prev = next;
        }

        time += increment;
    }

    return time;
}

int main()
{
}