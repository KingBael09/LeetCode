// ? 114. Flatten Binary Tree to Linked List
// ? https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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

void preOrder(TreeNode *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }

    v.push_back(root->val);
    preOrder(root->left, v);
    preOrder(root->right, v);
}

// Very bad Method;
void flatten(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    vector<int> v;

    preOrder(root, v);
    root->left = nullptr;
    root->right = nullptr;
    TreeNode *curr = root;
    root->val = v[0];

    for (int i = 1; i < v.size(); i++)
    {

        TreeNode *newNode = new TreeNode(v[i]);
        curr->right = newNode;
        curr = curr->right;
    }

    return;
}
// Recusive Method
TreeNode *dummy = nullptr;

void flattenRecurse(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    // reverse of preorder right->left->curr
    flattenRecurse(root->right);
    flattenRecurse(root->left);
    root->right = dummy;
    root->left = nullptr;
    dummy = root;
}

// Itr Method

void flattenItr(TreeNode *root)
{
    while (root)
    {
        if (root->left)
        {
            TreeNode *prev = root->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));

    flatten(root);
}