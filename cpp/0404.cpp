// ? 404. Sum of Left Leaves
// ? https://leetcode.com/problems/sum-of-left-leaves/description/

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

int sumOfLeftLeaves(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int ans = 0;

    if (root->left && !root->left->left && !root->left->right)
    {
        ans += root->left->val;
    }

    ans += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    return ans;
}

int main()
{
}