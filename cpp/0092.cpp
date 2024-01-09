// ? 92. Reverse Linked List II
// ? https://leetcode.com/problems/reverse-linked-list-ii/description/

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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || left == right)
    {
        return head;
    }

    ListNode *dummy = new ListNode(0, head);
    ListNode *prev_node = dummy;

    int count = 1;

    while (count < left)
    {
        prev_node = prev_node->next;
        count++;
    }

    ListNode *curr = prev_node->next;

    while (count < right)
    {
        ListNode *next_node = curr->next;
        curr->next = next_node->next;
        next_node->next = prev_node->next;
        prev_node->next = next_node;
        count++;
    }

    return dummy->next;
}

auto rr(ListNode *head, int left, int right)
{
    if (!head || left == right)
    {
        return head;
    }

    ListNode *dummy = new ListNode(0, head);
    ListNode *prev_node = dummy;

    int count = 1;

    while (count++ < left)
    {
        prev_node = prev_node->next;
    }

    ListNode *curr = prev_node->next;

    while (count++ <= right)
    {
        ListNode *next_node = curr->next;
        curr->next = next_node->next;
        next_node->next = prev_node->next;
        prev_node->next = next_node;
    }

    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode *result = reverseBetween(head, 2, 4);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
}