// ? 225. Implement Stack using Queues
// ? https://leetcode.com/problems/implement-stack-using-queues/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class MyStackWithDeque
{
private:
    deque<int> q;

public:
    MyStackWithDeque()
    {
    }

    void push(int x)
    {
        q.push_back(x);
    }

    int pop()
    {
        int x = q.back();
        q.pop_back();
        return x;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};

// With Queue Only
class MyStack
{
    queue<int> q, hq;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        while (!q.empty())
        {
            hq.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!hq.empty())
        {
            q.push(hq.front());
            hq.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
}