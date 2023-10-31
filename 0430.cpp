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

int main()
{
}