// ? 783. Minimum Distance Between BST Nodes
// ? https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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

vector<TreeNode *> vec;

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    vec.push_back(root);
    inorder(root->right);
}

// we know that inorder traversal of BST is sorted
int minDiffInBST(TreeNode *root)
{
    inorder(root);

    int ans = INT_MAX;
    int sz = vec.size();

    for (int i = 1; i < sz; i++)
    {
        ans = min(ans, vec[i]->val - vec[i - 1]->val);
    }

    return ans;
}

int main()
{
}
