// ? 429. N-ary Tree Level Order Traversal
// ? https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    if (!root)
    {
        return {};
    }

    deque<Node *> q = {root};
    vector<vector<int>> ans;

    while (!q.empty())
    {
        int sz = q.size();

        vector<int> level;
        while (sz--)
        {
            auto node = q.front();
            q.pop_front();

            level.push_back(node->val);

            for (auto child : node->children)
            {
                q.push_back(child);
            }
        }

        ans.push_back(level);
    }

    return ans;
}

int main()
{
}