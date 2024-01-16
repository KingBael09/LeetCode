// ? 380. Insert Delete GetRandom O(1)
// ? https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class RandomizedSet
{
private:
    unordered_set<int> s;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (s.count(val))
        {
            return false;
        }

        s.insert(val);

        return true;
    }

    bool remove(int val)
    {
        if (!s.count(val))
        {
            return false;
        }

        s.erase(val);
        return true;
    }

    int getRandom()
    {
        int idx = rand() % s.size();
        return *next(s.begin(), idx);
    }
};

int main()
{
}