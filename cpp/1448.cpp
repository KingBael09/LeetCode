// ? 1448. Count Good Nodes in Binary Tree
// ? https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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

int ct = 0;

void helper(TreeNode *root, int max)
{
    if (!root)
    {
        return;
    }

    if (root->val >= max)
    {
        ct++;
        max = root->val;
    }

    helper(root->right, max);
    helper(root->left, max);
}

int goodNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    helper(root, root->val);

    return ct;
}

int main()
{
}