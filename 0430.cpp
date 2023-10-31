// ? 430. Flatten a Multilevel Doubly Linked List
// ? https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

Node *flatten(Node *head)
{
    auto curr = head;
    while (curr)
    {
        if (!curr->child)
        {
            curr = curr->next;
            continue;
        }

        auto tail = curr->child;

        while (tail->next)
        {
            tail = tail->next;
        }

        tail->next = curr->next;

        if (curr->next)
        {
            curr->next->prev = tail;
        }

        curr->next = curr->child;
        curr->child->prev = curr;
        curr->child = nullptr;
    }

    return head;
}

Node *flattenBetter(Node *head)
{
    auto curr = head;
    while (curr)
    {
        if (!curr->child)
        {
            curr = curr->next;
            continue;
        }

        auto tail = curr->child;

        auto look_out = curr;
        // lookout allows us to jump without re-traversion to nodes with children

        while (tail->next)
        {
            if (tail->child)
            {
                look_out = tail;
            }
            tail = tail->next;
        }

        tail->next = curr->next;

        if (curr->next)
        {
            curr->next->prev = tail;
        }

        curr->next = curr->child;
        curr->child->prev = curr;
        curr->child = nullptr;
        curr = look_out;
    }

    return head;
}

int main()
{
}