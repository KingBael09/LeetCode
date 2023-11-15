// ? 590. N-ary Tree Postorder Traversal
// ? https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

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

vector<int> ans;
vector<int> postorder(Node *root)
{
    if (!root)
    {
        return ans;
    }

    for (auto const i : root->children)
    {
        postorder(i);
    }

    ans.push_back(root->val);

    return ans;
}

int main()
{
}