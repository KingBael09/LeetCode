// ? 61. Rotate List
// ? https://leetcode.com/problems/rotate-list/description/
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

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head)
    {
        return head;
    }

    ListNode *curr = head;

    int size = 1;

    while (curr->next)
    {
        curr = curr->next;
        size++;
    }

    curr->next = head;

    k = k % size;
    k = size - k;

    while (k--)
    {
        curr = curr->next;
    }

    head = curr->next;
    curr->next = nullptr;

    return head;
}

int main()
{
}