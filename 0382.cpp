// ? 382. Linked List Random Node
// ? https://leetcode.com/problems/linked-list-random-node/description/

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

class Solution
{
private:
    vector<int> nodes;

public:
    Solution(ListNode *head)
    {
        while (head)
        {
            nodes.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom()
    {
        int index = rand() % nodes.size();
        return nodes[index];
    }
};

int main()
{
}