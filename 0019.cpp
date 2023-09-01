// ? 19. Remove Nth Node From End of List
// ? https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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

int lengthOfLinkedList(ListNode *head)
{
    ListNode *tail = head;
    int count = 0;

    while (tail)
    {
        count++;
        tail = tail->next;
    }

    return count;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    n = lengthOfLinkedList(head) - n;

    if (n == 0)
    {
        return head->next;
    }

    ListNode *curr = head, *prev = nullptr;

    while (n--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    return head;
}

ListNode *removeNthFromEndOptimized(ListNode *head, int n)
{
    ListNode *slow = head, *fast = head;

    while (n != 0 && fast)
    {
        fast = fast->next;
        n--;
    }

    ListNode *prev = nullptr;

    while (fast)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }

    if (prev == nullptr)
    {
        ListNode *newHead = slow->next;
        delete slow;
        return newHead;
    }

    prev->next = slow->next;

    delete (slow);

    return head;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int kthElem = 2;

    ListNode *result = removeNthFromEnd(head, kthElem);

    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
}