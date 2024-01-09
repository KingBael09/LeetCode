// ? 938. Range Sum of BST
// ? https://leetcode.com/problems/range-sum-of-bst/description/

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

int sum = 0;

void traverse(TreeNode *root, int &low, int &high)
{
    if (!root)
    {
        return;
    }
    traverse(root->left, low, high);
    if (root->val <= high && root->val >= low)
    {
        sum += root->val;
    }
    traverse(root->right, low, high);
}

void betterTraverse(TreeNode *root, int &low, int &high)
{
    if (!root)
    {
        return;
    }

    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
        betterTraverse(root->left, low, high);
        betterTraverse(root->right, low, high);
    }
    else if (root->val >= high)
    {
        betterTraverse(root->left, low, high);
    }
    else if (root->val <= low)
    {
        betterTraverse(root->right, low, high);
    }
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    traverse(root, low, high);
    return sum;
}

int main()
{
}