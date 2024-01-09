// ? 1609. Even Odd Tree
// ? https://leetcode.com/problems/even-odd-tree/description/

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

bool isEvenOddTree(TreeNode *root)
{
    deque<TreeNode *> q;

    q.push_back(root);

    int level = 0;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> level_nodes;
        while (sz--)
        {
            TreeNode *node = q.front();
            q.pop_front();

            if (level % 2 != 0)
            {
                if (node->val % 2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if (node->val % 2 == 0)
                {
                    return false;
                }
            }

            level_nodes.push_back(node->val);

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }

        for (int i = 1; i < level_nodes.size(); i++)
        {
            if (level % 2 == 0)
            {
                if (level_nodes[i - 1] >= level_nodes[i])
                {
                    return false;
                }
            }
            else
            {
                if (level_nodes[i - 1] <= level_nodes[i])
                {
                    return false;
                }
            }
        }

        level++;
    }

    return true;
}

bool isEvenOddTreeWithoutVector(TreeNode *root)
{
    deque<TreeNode *> q;

    q.push_back(root);

    int level = 0;

    while (!q.empty())
    {
        int sz = q.size();

        TreeNode *prev = nullptr;

        while (sz--)
        {
            TreeNode *node = q.front();
            q.pop_front();

            if (level % 2 == 0)
            {
                if (prev && node->val <= prev->val || node->val % 2 == 0)
                {
                    return false;
                }
            }
            else
            {
                if (prev && node->val >= prev->val || node->val % 2 != 0)
                {
                    return false;
                }
            }

            prev = node;

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }

        level++;
    }

    return true;
}

int main()
{
    TreeNode *ten = new TreeNode(3, new TreeNode(12), new TreeNode(8));
    TreeNode *four = new TreeNode(4, new TreeNode(7, new TreeNode(6), nullptr), new TreeNode(9, nullptr, new TreeNode(2)));
    TreeNode *root = new TreeNode(1, new TreeNode(10, ten, nullptr), four);
}