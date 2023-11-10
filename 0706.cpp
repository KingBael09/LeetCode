// ? 706. Design HashMap
// ? https://leetcode.com/problems/design-hashmap/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class MyHashMap
{
private:
    unordered_map<int, int> m;

public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        m[key] = value;
    }

    int get(int key)
    {
        return m.find(key) != m.end() ? m[key] : -1;
    }

    void remove(int key)
    {
        m.erase(key);
    }
};

class MyHashMap2
{
public:
    vector<int> m;

    MyHashMap2()
    {
        int siz = 1e6 + 1;
        m.resize(siz);
        fill(m.begin(), m.end(), -1);
    }

    void put(int key, int value)
    {
        m[key] = value;
    }

    int get(int key)
    {
        return m[key];
    }

    void remove(int key)
    {
        m[key] = -1;
    }
};

int main()
{
}