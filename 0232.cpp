// ? 232. Implement Queue using Stacks
// ? https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class BadQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    BadQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        int x = output.top();
        output.pop();

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int peek()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        int x = output.top();

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }

        return x;
    }

    bool empty()
    {
        return input.empty();
    }
};

class MyQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue()
    {
    }

    // it makes it so that only first operation requires fetching rest others don't
    void move()
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            move();
        }

        int x = output.top();
        output.pop();

        return x;
    }

    int peek()
    {
        if (output.empty())
        {
            move();
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() and output.empty();
    }
};

int main()
{
}