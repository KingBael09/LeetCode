// ? 235. Lowest Common Ancestor of a Binary Search Tree
// ? https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestorOther(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || p == root || q == root)
    {
        return root;
    }

    auto left = lowestCommonAncestorOther(root->left, p, q);
    auto right = lowestCommonAncestorOther(root->right, p, q);

    if (!left && !right)
    {
        return NULL;
    }

    if (!left && right || !right && left)
    {
        return left ? left : right;
    }

    return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
    {
        return root;
    }

    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    return root;
}