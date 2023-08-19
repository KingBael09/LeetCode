// ? 237. Delete Node in a Linked List
// ? https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{

    ListNode *temp = node->next;

    node->val = temp->val;

    node->next = temp->next;
}

void deleteNodeEfficiently(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}

int main()
{
    // TODO: Write Driver code
}
