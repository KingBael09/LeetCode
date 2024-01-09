// ? 538. Convert BST to Greater Tree
// ? https://leetcode.com/problems/convert-bst-to-greater-tree/description/

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

vector<TreeNode *> v;

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    v.push_back(root);
    inorder(root->right);
}

TreeNode *convertBSTWIthArray(TreeNode *root)
{
    inorder(root);
    // we get ascending order

    int n = v.size() - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        v[i]->val += v[i + 1]->val;
        // orignal + sum of keys greater
    }

    return root;
}

// Without using array

int sum = 0;

void helper(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    // we are running the inorder in reverse to get elements which are larger than current

    helper(root->right);

    int prev = root->val;
    root->val += sum;
    sum += prev;

    helper(root->left);
}

TreeNode *convertBST(TreeNode *root)
{
    helper(root);

    return root;
}

int main()
{
}