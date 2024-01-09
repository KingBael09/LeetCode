// ? 226. Invert Binary Tree
// ? https://leetcode.com/problems/invert-binary-tree/description/

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

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }

    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = temp;

    invertTree(root->right);
    invertTree(root->left);

    return root;
}

TreeNode *makesMuchSenseMethod(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main()
{
    // TODO: Write driver code
}