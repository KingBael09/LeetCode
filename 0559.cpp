// ? 559. Maximum Depth of N-ary Tree
// ? https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/

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

int maxDepth(Node *root)
{

    if (!root)
    {
        return 0;
    }

    int depth = 0;

    for (auto const i : root->children)
    {
        depth = max(depth, maxDepth(i));
    }

    return depth + 1;
}