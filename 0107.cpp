// ? 107. Binary Tree Level Order Traversal II
// ? https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> ans;

    if (!root)
    {
        return ans;
    }

    deque<TreeNode *> q; // This would have worked even if we have used a queue
    TreeNode *current;
    q.push_back(root); // entry

    while (!q.empty())
    {
        vector<int> currentLevel;
        int len = q.size();

        for (int i = 0; i < len; i++)
        {
            current = q.front();
            q.pop_front();

            currentLevel.push_back(current->val);

            if (current->left != nullptr)
            {
                q.push_back(current->left);
            }
            if (current->right != nullptr)
            {
                q.push_back(current->right);
            }
        }

        ans.push_back(currentLevel);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
}