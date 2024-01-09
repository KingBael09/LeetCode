// ? 109. Convert Sorted List to Binary Search Tree
// ? https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(vector<int> &nums, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = left + (right - left) / 2;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = createTree(nums, left, mid - 1);
    root->right = createTree(nums, mid + 1, right);

    return root;
}

TreeNode *sortedListToBST_Works_but_Wasteful(ListNode *head)
{
    auto curr = head;

    vector<int> nums;

    while (curr)
    {
        nums.push_back(curr->val);
        curr = curr->next;
    }

    return createTree(nums, 0, nums.size() - 1);
}

TreeNode *sortedListToBST_Wierd(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    auto slow = head;
    auto fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Break list

    if (prev)
    {
        prev->next = nullptr;
    }

    auto root = new TreeNode(slow->val);

    if (slow != head)
    {
        root->left = sortedListToBST_Wierd(head);
    }
    else
    {
        root->right = nullptr;
    }
    root->right = sortedListToBST_Wierd(slow->next);

    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    if (!head->next)
    {
        return new TreeNode(head->val);
    }

    auto slow = head;
    auto fast = head;

    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;

    auto root = new TreeNode(slow->val);

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}

int main()
{
}