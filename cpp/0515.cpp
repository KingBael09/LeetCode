// ? 515. Find Largest Value in Each Tree Row
// ? https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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

vector<int> largestValues(TreeNode *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }

    deque<TreeNode *> q;

    q.push_back(root);

    while (!q.empty())
    {
        int sz = q.size();
        int mx = INT_MIN;
        while (sz--)
        {
            auto node = q.front();
            q.pop_front();

            mx = max(mx, node->val);

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }
        res.push_back(mx);
    }

    return res;
}

vector<int> largestValues2(TreeNode *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }

    deque<TreeNode *> q;

    q.push_back(root);

    while (!q.empty())
    {
        int sz = q.size();
        priority_queue<int> pq;
        while (sz--)
        {
            auto node = q.front();
            q.pop_front();

            pq.push(node->val);

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }
        res.push_back(pq.top());
    }

    return res;
}

int main()
{
}