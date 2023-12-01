// ? 124. Binary Tree Maximum Path Sum
// ? https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

int max_path = INT_MIN;

int depth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    // using unsigned short is much better for qn
    auto left = max(0, depth(root->left));   // unsigned short
    auto right = max(0, depth(root->right)); // unsigned short

    max_path = max(max_path, left + right + root->val);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode *root)
{
    depth(root);
    return max_path;
}

int main()
{
}