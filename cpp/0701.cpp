// ? 701. Insert into a Binary Search Tree
// ? https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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

TreeNode *insertIntoBSTRecursive(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insertIntoBSTRecursive(root->left, val);
    }
    else
    {
        root->right = insertIntoBSTRecursive(root->right, val);
    }

    return root;
}

TreeNode *insertIntoBSTItr(TreeNode *root, int val)
{
    TreeNode *newNode = new TreeNode(val);
    if (!root)
    {
        return newNode;
    }

    TreeNode *curr = root;

    while (true)
    {
        if (val < curr->val)
        {
            if (!curr->left)
            {
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
            {
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
    }

    return root;
}

int main()
{
}