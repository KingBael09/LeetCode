// ? 543. Diameter of Binary Tree
// ? https://leetcode.com/problems/diameter-of-binary-tree/description/

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

int max_diameter = 0;

int depth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    max_diameter = max(max_diameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    depth(root);
    return max_diameter;
}

int main()
{
}