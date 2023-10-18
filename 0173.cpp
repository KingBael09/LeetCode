// ? 173. Binary Search Tree Iterator
// ? https://leetcode.com/problems/binary-search-tree-iterator/description/

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

class BSTIterator
{
private:
    int curr;
    vector<int> order;
    void traverse(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        traverse(root->left);
        order.push_back(root->val);
        traverse(root->right);
    }

public:
    BSTIterator(TreeNode *root)
    {
        traverse(root);
        curr = 0;
    }

    int next()
    {
        return order[curr++];
    }

    bool hasNext()
    {
        return curr < order.size();
    }
};

class BSTIterator2
{
private:
    int curr;
    vector<TreeNode *> order;
    void traverse(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        traverse(root->left);
        order.push_back(root);
        traverse(root->right);
    }

public:
    BSTIterator2(TreeNode *root)
    {
        traverse(root);
        curr = 0;
    }

    int next()
    {
        return order[curr++]->val;
    }

    bool hasNext()
    {
        return curr < order.size();
    }
};

int main()
{
}