// ? 24. Swap Nodes in Pairs
// ? https://leetcode.com/problems/swap-nodes-in-pairs/description/

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

// This cannot be the correct solution as we modify the value;
ListNode *swapPairsByModification(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    deque<int> even; // contains odd places values it is to be placed in even place
    deque<int> odd;  // contains even places values it is to be placed in odd place

    ListNode *curr = head;

    int i = 1;

    while (curr)
    {
        if (i % 2 == 0)
        {
            // even position
            odd.push_back(curr->val);
        }
        else
        {
            even.push_back(curr->val);
        }
        curr = curr->next;
        i++;
    }

    curr = head;
    i = 1;
    while (curr)
    {
        if (i % 2 == 0)
        {
            if (even.empty())
            {
                break;
            }
            curr->val = even.front();
            even.pop_front();
        }
        else
        {
            if (odd.empty())
            {
                break;
            }
            curr->val = odd.front();
            odd.pop_front();
        }
        curr = curr->next;
        i++;
    }

    return head;
}
// Better Solution
ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *dummy = new ListNode();
    dummy->next = head;

    ListNode *curr = head;
    ListNode *prev = dummy;

    while (curr && curr->next)
    {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = curr->next;
    }

    return dummy->next;
}

// Recursive Solution
ListNode *swapPairsResursive(ListNode *head)
{
    ListNode *ptr;
    if (head && head->next)
    {
        ptr = head->next;
        ListNode *nextPtr = head->next;
        ListNode *nextNextPtr = head->next->next;
        nextPtr->next = head;
        head->next = swapPairsResursive(nextNextPtr);
    }
    else
    {
        ptr = head;
    }

    return ptr;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    swapPairs(head);
}