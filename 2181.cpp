
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

ListNode *mergeNodes(ListNode *head)
{

    auto node = new ListNode(0);
    auto ptr = node;

    int sum = 0;
    while (head = head->next)
    {
        if (head->val == 0)
        {
            node->next = new ListNode(sum);
            sum = 0;
            node = node->next;
        }
        else
        {
            sum += head->val;
        }
    }

    return ptr->next;
}

int main()
{
}