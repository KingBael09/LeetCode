// ? 83. Remove Duplicates from Sorted List
// ? https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
    {
        return head;
    }

    ListNode *root = head;
    ListNode *next = head->next;
    while (next)
    {
        if (next->val == head->val)
        {
            head->next = next->next;
            next = head->next;
        }
        else
        {
            // ListNode *t = head->next; // Deleting actually results in bad performance
            head = head->next;
            next = next->next;
            // delete t;
        }
    }

    return root;
}

// This performs arguably worse than previouse
ListNode *beterDeleteDuplicte(ListNode *head)
{
    ListNode *curr = head;

    while (curr && curr->next)
    {
        if (curr->next->val == curr->val)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    ListNode *root = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    ListNode *temp = deleteDuplicates(root);

    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}