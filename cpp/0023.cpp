// ? 23. Merge k Sorted Lists
// ? https://leetcode.com/problems/merge-k-sorted-lists/description/

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

ListNode *merge(ListNode *left, ListNode *right)
{
    auto head = new ListNode(-1);
    auto tail = head;

    while (left && right)
    {
        if (left->val < right->val)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }

        tail = tail->next;
    }

    tail->next = left ? left : right;

    return head->next;
}

ListNode *helper(vector<ListNode *> &lists, int start, int end)
{
    if (start == end)
    {
        return lists[start];
    }

    int mid = start + (end - start) / 2;

    auto left = helper(lists, start, mid);
    auto right = helper(lists, mid + 1, end);
    return merge(left, right);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return nullptr;
    }

    return helper(lists, 0, lists.size() - 1);
}

// ---------------------------------------------------------------------------------

typedef pair<int, ListNode *> Pair;

ListNode *mergeKLists1(vector<ListNode *> &lists)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    for (const auto &node : lists)
    {
        if (!node)
        {
            continue;
        }
        pq.push({node->val, node});
    }

    auto head = new ListNode(0);

    auto curr = head;

    while (!pq.empty())
    {
        auto [_, node] = pq.top();

        pq.pop();

        if (node->next)
        {
            pq.push({node->next->val, node->next});
        }

        curr->next = node;
        curr = curr->next;
    }

    return head->next;
}

// ---------------------------------------------------------------------------------

struct Compare
{
public:
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists2(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

    for (const auto &node : lists)
    {
        if (!node)
        {
            continue;
        }
        pq.push(node);
    }

    auto head = new ListNode(0);
    auto tail = head;

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        tail->next = node;
        tail = tail->next;

        if (node->next)
        {
            pq.push(node->next);
        }
    }

    return head->next;
}

int main()
{
}