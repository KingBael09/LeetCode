// ? 904. Fruit Into Baskets
// ? https://leetcode.com/problems/fruit-into-baskets/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMaxFruits(vector<int> fruits)
{
    int len = fruits.size();

    unordered_map<int, bool> mp;
    int start = 0;
    int end = 0;

    int maxTrees = 0;

    while (end < len)
    {
        int current = fruits[end];
        int windowSize = end - start + 1;
        // if there is room for fruits and the current is not of the same type as filled
        if (mp.size() < 2 && !mp[current])
        {
            mp[current] = true;
            maxTrees = max(maxTrees, windowSize);
        }
        else if (mp[current])
        {
            maxTrees = max(maxTrees, windowSize);
        }
        else
        {
            mp.clear();
            mp[fruits[end - 1]] = true;
            mp[fruits[end]] = true;

            start = end - 1;

            while (fruits[start] == fruits[start - 1])
            {
                start--;
            }
        }

        end++;
    }

    return maxTrees;
}

int main()
{

    vector<int> fruits{1, 2, 3, 2, 2};

    int len = getMaxFruits(fruits);

    cout << endl
         << len;
}