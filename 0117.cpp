// ? 117. Populating Next Right Pointers in Each Node II
// ? https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
    {
        return root;
    }

    deque<Node *> q;

    q.push_back(root);
    Node *node;
    while (!q.empty())
    {
        int sz = q.size();
        vector<Node *> v;

        while (sz--)
        {
            node = q.front();
            q.pop_front();
            v.push_back(node);
            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i]->next = v[i + 1];
        }
    }

    return root;
}

// TODO: There is also a recursive solution

int main()
{
}