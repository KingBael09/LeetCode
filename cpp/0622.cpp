// ? 622. Design Circular Queue
// ? https://leetcode.com/problems/design-circular-queue/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

class MyCircularQueue
{
private:
    int size;
    int max_size;
    Node *root;
    Node *rear;

public:
    MyCircularQueue(int k)
    {
        size = 0;
        max_size = k;
        root = nullptr;
        rear = nullptr;
    }

    bool enQueue(int value)
    {
        if (size == max_size)
        {
            return false;
        }

        Node *node = new Node(value);

        if (!root)
        {
            root = rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }

        rear->next = root;
        size++;

        return true;
    }

    bool deQueue()
    {
        if (size == 0)
        {
            return false;
        }

        Node *temp = root;

        if (rear == root)
        {
            rear = root = nullptr;
        }
        else
        {
            root = root->next;
            rear->next = root;
        }

        delete (temp);

        size--;

        return true;
    }

    int Front()
    {
        if (!root)
        {
            return -1;
        }

        return root->data;
    }

    int Rear()
    {
        if (!root)
        {
            return -1;
        }

        return rear->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == max_size;
    }
};

int main()
{
}