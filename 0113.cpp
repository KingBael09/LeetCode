// ? 113. Path Sum II
// ? https://leetcode.com/problems/path-sum-ii/description/

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

vector<vector<int>> ans;

void helper(TreeNode *root, int target, vector<int> &path)
{
    if (!root)
    {
        return;
    }

    int val = root->val;
    path.push_back(val);

    if (!root->left && !root->right)
    {
        if (target == val)
        {
            ans.push_back(path);
        }
    }

    helper(root->left, target - val, path);
    helper(root->right, target - val, path);
    path.pop_back();

    return;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> path;

    helper(root, targetSum, path);

    return ans;
}

int main()
{
}