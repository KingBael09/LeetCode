// ? 222. Count Complete Tree Nodes
// ? https://leetcode.com/problems/count-complete-tree-nodes/description/

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

void count(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    ct++;

    count(root->right);
    count(root->left);
}

int countNodesBad(TreeNode *root)
{
    count(root);
    return ct;
}

// Smaller method;

int countNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int count = 1 + countNodes(root->left) + countNodes(root->right);
    root->left = nullptr, root->right = nullptr; // this just removes the reference to the node;

    return count;
}

int main()
{
}