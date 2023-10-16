// ? 328. Odd Even Linked List
// ? https://leetcode.com/problems/odd-even-linked-list/description/

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

ListNode *oddEvenList(ListNode *head)
{
    if (!head)
    {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;

    ListNode *even_head = even;

    while (even && even->next)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }

    odd->next = even_head;

    return head;
}

int main()
{
}