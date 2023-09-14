// ? 1721. Swapping Nodes in a Linked List
// ? https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getListLen(ListNode *head)
{
    int len = 0;

    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

ListNode *swapNodes(ListNode *head, int k)
{
    int len = getListLen(head);

    int end = len - k + 1;
    int start = k;

    if (end < len / 2)
    {
        start = end;
        end = k;
    }

    ListNode *curr = head;

    int i = 1;

    ListNode *first = nullptr;
    ListNode *last = nullptr;

    while (curr)
    {
        if (i == start)
        {
            first = curr;
        }
        if (i == end)
        {
            last = curr;
        }
        curr = curr->next;
        i++;
    }

    int temp = first->val;
    first->val = last->val;
    last->val = temp;

    return head;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    swapNodes(head, 2);
}