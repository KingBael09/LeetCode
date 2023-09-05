// ? 138. Copy List with Random Pointer
// ? https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{

    unordered_map<Node *, Node *> newList;

    Node *curr = head;

    while (curr)
    {
        newList[curr] = new Node(curr->val);
        curr = curr->next;
    }

    curr = head;

    while (curr)
    {
        newList[curr]->next = newList[curr->next];
        newList[curr]->random = newList[curr->random];
        curr = curr->next;
    }

    return newList[head];
}

// TODO: There is another method for this by interweaving the nodes -> try that

int main()
{
    // TODO: I am too lazy to write driver code here
}
