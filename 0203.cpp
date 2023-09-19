// ? 203. Remove Linked List Elements
// ? https://leetcode.com/problems/remove-linked-list-elements/description/

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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *ptr = head;
    ListNode *prev = nullptr;
    while (ptr)
    {
        if (ptr->val == val)
        {
            if (!prev)
            {
                // it is at start
                head = head->next;
                ptr = head;
                continue;
            }
            else
            {

                prev->next = ptr->next;
                ptr = ptr->next;
                continue;
            }
        }
        prev = ptr;
        ptr = ptr->next;
    }

    return head;
}

ListNode *removeElementsBetter(ListNode *head, int val)
{
    if (!head)
    {
        return head;
    }

    while (head && head->val == val)
    {
        head = head->next;
    }

    ListNode *prev = head;
    ListNode *curr = head;

    while (curr)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }

    return head;
}

int main()
{
    // Too lazy to write code
}