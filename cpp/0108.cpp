// ? 108. Convert Sorted Array to Binary Search Tree
// ? https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

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

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return createTree(nums, 0, nums.size() - 1);
}

void _traverse(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    _traverse(root->left);
    cout << root->val << " ";
    _traverse(root->right);
}

int main()
{
    vector<int> nums{-10, -3, 0, 5, 9};

    _traverse(sortedArrayToBST(nums));
}