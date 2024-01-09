// ? 103. Binary Tree Zigzag Level Order Traversal
// ? https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (!root)
    {
        return ans;
    }

    deque<TreeNode *> q;
    q.push_back(root);

    bool dir = false;

    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();

        while (size--)
        {
            root = q.front();
            q.pop_front();

            level.push_back(root->val);

            if (root->left)
            {
                q.push_back(root->left);
            }
            if (root->right)
            {
                q.push_back(root->right);
            }
        }

        if (dir)
        {
            // This is very bad
            reverse(level.begin(), level.end());
        }

        dir = !dir;

        ans.push_back(level);
    }

    return ans;
}

vector<vector<int>> zigzagLevelOrderBetter(TreeNode *root)
{
    vector<vector<int>> ans;

    if (!root)
    {
        return ans;
    }

    deque<TreeNode *> q;
    q.push_back(root);

    bool dir = true;

    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();

        while (size--)
        {
            if (!dir)
            {
                root = q.back();
                q.pop_back();

                level.push_back(root->val);

                if (root->right)
                {
                    q.push_front(root->right);
                }
                if (root->left)
                {
                    q.push_front(root->left);
                }
            }
            else
            {
                root = q.front();
                q.pop_front();

                level.push_back(root->val);

                if (root->left)
                {
                    q.push_back(root->left);
                }
                if (root->right)
                {
                    q.push_back(root->right);
                }
            }
        }
        ans.push_back(level);
        dir = !dir;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    for (auto i : zigzagLevelOrder(root))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}