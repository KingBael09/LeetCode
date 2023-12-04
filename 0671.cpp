// ? 671. Second Minimum Node In a Binary Tree
// ? https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

set<int> s;
void dfs(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    s.insert(root->val);
    dfs(root->left);
    dfs(root->right);
}
int findSecondMinimumValue(TreeNode *root)
{
    dfs(root);

    if (s.size() < 2)
    {
        return -1;
    }

    return *(++s.begin());
}