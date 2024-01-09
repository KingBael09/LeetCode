// ? 104. Maximum Depth of Binary Tree
// ? https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

int getDepth(TreeNode *root, int count)
{
    if (!root)
    {
        return count;
    }

    return max(getDepth(root->left, count + 1), getDepth(root->right, count + 1));
}

int maxDepthItWorksButIsBig(TreeNode *root)
{

    int count = 0;
    if (root == NULL)
    {
        return count + 1;
    }

    return max(getDepth(root->left, count), getDepth(root->right, count)) + 1;
}

// Smaller and much more optimized
int maxDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{

    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << maxDepthItWorksButIsBig(root);
}