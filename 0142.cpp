// ? 142. Linked List Cycle II
// ? https://leetcode.com/problems/linked-list-cycle-ii/description/

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

/**
 * ### Algorithm: Floyd's tortoise and hare cycle finding algorithm
 * This algorithm uses two pointers to find the presence of cycle
 * then point one of the pointer to the start of the list iterate both of the pointers
 * at same speed until they meet, they will meet at the start of the cycle (i don know why though)
 *
 */
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            // We are inside the cycle;
            // finding the start of cycle
            slow = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return nullptr;
}

int main()
{
    // TOO Lazy to write driver code
}