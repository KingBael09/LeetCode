// ? 101. Symmetric Tree
// ? https://leetcode.com/problems/symmetric-tree/description/

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

bool check(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
    {
        return true; // both nodes are present
    }
    if (!left || !right)
    {
        return false; // only one node is present
    }
    if (left->val == right->val)
    {
        return check(left->left, right->right) && check(left->right, right->left);
        // check for their respective children
    }

    return false;
}

bool isSymmetric(TreeNode *root)
{
    return check(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2));

    cout << isSymmetric(root);
}