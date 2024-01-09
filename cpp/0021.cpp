// ? 21. Merge Two Sorted Lists
// ? https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

ListNode *workingMergeTwoList(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode();

    ListNode *tail = head;

    ListNode *l1 = list1;
    ListNode *l2 = list2;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }

    if (l1 == NULL)
    {
        tail->next = l2;
    }
    if (l2 == NULL)
    {
        tail->next = l1;
    }

    return head->next;
}

int main()
{
    vector<int> list1{1, 2, 4};
    vector<int> list2{1, 3, 4};

    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    for (auto i : list1)
    {
        ListNode *newNode = new ListNode;

        newNode->val = i;
        newNode->next = NULL;

        if (l1 == NULL)
        {
            l1 = newNode;
        }
        else
        {
            ListNode *current = l1;

            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    for (auto i : list2)
    {
        ListNode *newNode = new ListNode;

        newNode->val = i;
        newNode->next = NULL;

        if (l2 == NULL)
        {
            l2 = newNode;
        }
        else
        {
            ListNode *current = l2;

            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    ListNode *head = workingMergeTwoList(l1, l2);

    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
}