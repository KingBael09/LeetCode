// ? 1302. Deepest Leaves Sum
// ? https://leetcode.com/problems/deepest-leaves-sum/description/

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

int deepestLeavesSum(TreeNode *root)
{
    deque<TreeNode *> q;

    q.push_back(root);

    int sum = 0;

    while (!q.empty())
    {
        int n = q.size();
        sum = 0;

        while (n--)
        {
            TreeNode *node = q.front();
            q.pop_front();

            sum += node->val;

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }
    }

    return sum;
}

int main()
{
}