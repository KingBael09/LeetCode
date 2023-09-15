// ? 148. Sort List
// ? https://leetcode.com/problems/sort-list/description/

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

// This doesn't solve in constant space
ListNode *sortListWithExtraSpace(ListNode *head)
{
    ListNode *curr = head;
    vector<int> ans;

    while (curr)
    {
        ans.push_back(curr->val);
        curr = curr->next;
    }
    sort(ans.begin(), ans.end());

    curr = head;
    for (auto i : ans)
    {
        curr->val = i;
        curr = curr->next;
    }

    return head;
}

ListNode *merge(ListNode *left, ListNode *right)
{
    ListNode *dummy = new ListNode();

    ListNode *curr = dummy;

    while (left && right)
    {
        if (left->val <= right->val)
        {
            curr->next = left;
            left = left->next;
        }
        else
        {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }

    if (left)
    {
        curr->next = left;
    }
    if (right)
    {
        curr->next = right;
    }

    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *breaker;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        breaker = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    breaker->next = nullptr;
    // breaking the list into two halves

    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    return merge(left, right);
}

int main()
{
}