// ? 199. Binary Tree Right Side View
// ? https://leetcode.com/problems/binary-tree-right-side-view/

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

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
    {
        return {};
    }

    vector<int> ans;

    deque<TreeNode *> q;

    q.push_back(root);

    while (!q.empty())
    {
        TreeNode *node;
        int sz = q.size();

        while (sz--)
        {
            node = q.front();
            q.pop_front();

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }
        ans.push_back(node->val);
    }

    return ans;
}

/*-------------------------Recursive Method----------------------*/

vector<int> ans;

void helper(TreeNode *root, int level)
{
    if (!root)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->val);
    }

    helper(root->right, level + 1);
    helper(root->left, level + 1);
}

vector<int> rightSideViewRecursive(TreeNode *root)
{
    helper(root, 0);
    return ans;
}

int main()
{
}