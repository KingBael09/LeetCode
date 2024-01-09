// ? 2583. Kth Largest Sum in a Binary Tree
// ? https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

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

long long kthLargestLevelSum(TreeNode *root, int k)
{
    if (!root)
    {
        return -1;
    }

    vector<long long> v;

    deque<TreeNode *> q;
    q.push_back(root);

    while (!q.empty())
    {
        int size = q.size();
        long long sum = 0;

        while (size--)
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
        v.push_back(sum);
    }

    if (v.size() < k)
    {
        return -1;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    return v[k - 1];
}

long long kthLargestLevelSum2(TreeNode *root, int k)
{
    if (!root)
    {
        return -1;
    }

    vector<long long> v;

    deque<TreeNode *> q;
    TreeNode *node;

    q.push_back(root);

    while (!q.empty())
    {
        int size = q.size();
        long long sum = 0;

        while (size--)
        {
            node = q.front();
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
        v.push_back(sum);
    }

    if (v.size() < k)
    {
        return -1;
    }

    sort(v.begin(), v.end());

    return v[v.size() - k];
}

long long kthLargestLevelSumEfficient(TreeNode *root, int k)
{
    if (!root)
    {
        return -1;
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    deque<TreeNode *> q;
    TreeNode *node;

    q.push_back(root);

    while (!q.empty())
    {
        int size = q.size();
        long long sum = 0;

        while (size--)
        {
            node = q.front();
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
        pq.push(sum);
        while (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.size() == k ? pq.top() : -1;
}

// TODO: There exists a method using priority queue which is more efficient.

int main()
{
    TreeNode *root = new TreeNode(5, new TreeNode(8, new TreeNode(2, new TreeNode(4), new TreeNode(6)), new TreeNode(1)), new TreeNode(9, new TreeNode(3), new TreeNode(7)));

    cout << kthLargestLevelSum(root, 3);
}