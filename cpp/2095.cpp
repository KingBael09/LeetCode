// ? 2095. Delete the Middle Node of a Linked List
// ? https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *getList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev == nullptr)
    {
        return head = nullptr;
    }

    prev->next = slow->next;

    delete slow;

    return head;
}

int main()
{
    vector<int> list{1};

    ListNode *head = nullptr;

    for (auto i : list)
    {
        ListNode *newNode = new ListNode;

        newNode->data = i;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            ListNode *current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    getList(head);

    ListNode *current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
