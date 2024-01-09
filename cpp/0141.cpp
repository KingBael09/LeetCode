// ? 141. Linked List Cycle
// ? https://leetcode.com/problems/linked-list-cycle/description

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

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // TODO: Write driver code
}