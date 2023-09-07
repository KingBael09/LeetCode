// ? 234. Palindrome Linked List
// ? https://leetcode.com/problems/palindrome-linked-list/description/

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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *curr = head;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *save = slow->next;

    slow->next = nullptr;

    save = reverseList(save);

    while (save && head)
    {
        if (save->val != head->val)
        {
            return false;
        }

        save = save->next;
        head = head->next;
    }

    return true;
}

int main()
{
    // TOO Lazy to write drive code
}