// ? 145. Binary Tree Postorder Traversal
// ? https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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

void postOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    postOrder(root);
    return ans;
}

int main()
{
    // Too lazy to write code
}