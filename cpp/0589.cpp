// ? 589. N-ary Tree Preorder Traversal
// ? https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

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

vector<int> result;

void dfs(Node *root)
{
    if (!root)
    {
        return;
    }

    result.push_back(root->val);

    for (auto &child : root->children)
    {
        dfs(child);
    }
}

vector<int> preorder(Node *root)
{
    dfs(root);
    return result;
}

int main()
{
}