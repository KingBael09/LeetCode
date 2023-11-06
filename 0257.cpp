// ? 257. Binary Tree Paths
// ? https://leetcode.com/problems/binary-tree-paths/description/

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

vector<string> ans;

void helper(TreeNode *root, string s)
{
    if (!root)
    {
        return;
    }

    if (s.empty())
    {
        s += to_string(root->val);
    }
    else
    {
        s += "->" + to_string(root->val);
    }

    if (!root->left and !root->right)
    {
        ans.push_back(s);
    }

    helper(root->left, s);
    helper(root->right, s);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    helper(root, "");
    return ans;
}

int main()
{
}