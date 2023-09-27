// ? 100. Same Tree
// ? https://leetcode.com/problems/same-tree/description/

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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
    {
        return true;
    }

    if (p && q && p->val == q->val)
    {
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }

    return false;
}

int main()
{
    // too lazy to write driver code
}