// ? 206. Reverse Linked List
// ? https://leetcode.com/problems/reverse-linked-list/description/

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

ListNode *reverseList(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *curr = head;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    head = reverseList(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}