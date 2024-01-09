// ? 160. Intersection of Two Linked Lists
// ? https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// This cannot be good solution because it takes O(m.n) time
ListNode *getIntersectionNodeBad(ListNode *headA, ListNode *headB)
{
    ListNode *ptr = nullptr;
    ListNode *curr1 = headA;
    ListNode *curr2 = headB;
    while (curr1)
    {

        while (curr2)
        {
            if (curr1 == curr2)
            {
                ptr = curr1;
                return ptr;
            }
            curr2 = curr2->next;
        }
        curr2 = headB;

        curr1 = curr1->next;
    }

    return ptr;
}

int getLength(ListNode *head)
{
    int len = 0;

    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

// Above code can be converted into
ListNode *wtfThisWorks(ListNode *headA, ListNode *headB)
{
    ListNode *first = headA, *second = headB;

    while (first != second)
    {
        if (first)
        {
            first = first->next;
        }
        else
        {
            first = headA;
        }

        if (second)
        {
            second = second->next;
        }
        else
        {
            second = headB;
        }
    }

    return first;
}

// Much better solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
    {
        return nullptr;
    }

    int lenA = getLength(headA);
    int lenB = getLength(headB);

    if (lenA > lenB)
    {
        while (lenA > lenB)
        {
            headA = headA->next;
            lenA--;
        }
    }
    else
    {
        while (lenB > lenA)
        {
            headB = headB->next;
            lenB--;
        }
    }

    while (headA && headB)
    {
        if (headA == headB)
        {
            return headA;
        }

        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}

// Or convert into loop problem
ListNode *getIntersectionNodeWithLoop(ListNode *headA, ListNode *headB)
{
    ListNode *tail = headA;

    while (tail->next)
    {
        tail = tail->next;
    }

    tail->next = headA;

    ListNode *fast = headB;
    ListNode *slow = headB;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = headB;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            tail->next = nullptr;
            return slow;
        }
    }

    tail->next = nullptr;
    return nullptr;
}

int main()
{
}