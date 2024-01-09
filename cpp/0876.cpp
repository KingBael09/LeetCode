// ? 876. Middle of the Linked List
// ? https://leetcode.com/problems/middle-of-the-linked-list/description/

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

ListNode *middleNode(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    // Too lazy to write driver code
}