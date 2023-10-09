// ? 2. Add Two Numbers
// ? https://leetcode.com/problems/add-two-numbers/description/

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode();
    ListNode *temp = ans;

    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
        }
        if (l2)
        {
            sum += l2->val;
        }

        carry = 0;
        if (sum > 9)
        {
            carry = 1;
            sum = sum % 10;
        }
        temp->next = new ListNode(sum);
        temp = temp->next;

        if (l1)
        {

            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }

    // This could be moved up
    // if (carry)
    // {
    //     temp->next = new ListNode(carry);
    // }

    return ans->next;
}

// Much smaller method
ListNode *addTwoNumbersSmaller(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode();
    ListNode *temp = ans;

    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; // if sum is smaller than 10 carry is 0

        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }

    return ans->next;
}

int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    // ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    // ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));

    ListNode *ans = addTwoNumbers(l1, l2);

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
}
