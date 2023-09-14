// ? 144. Binary Tree Preorder Traversal
// ? https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

vector<int> ans;

void preOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    ans.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}
vector<int> preorderTraversal(TreeNode *root)
{
    preOrder(root);
    return ans;
}

int main()
{
    // Too lazy to write code
}