// ? 236. Lowest Common Ancestor of a Binary Tree
// ? https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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

TreeNode *lowestCommonAncestor(TreeNode *root, const TreeNode *p, const TreeNode *q)
{
    if (!root || root == p || root == q)
    {
        return root;
    }

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (!left)
    {
        return right;
    }
    if (!right)
    {
        return left;
    }

    return root;
}

int main()
{
}