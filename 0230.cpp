// ? 230. Kth Smallest Element in a BST
// ? https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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

vector<int> v;

void inorder(struct TreeNode *TreeNode)
{
    if (!TreeNode)
    {
        return;
    }

    inorder(TreeNode->left);
    v.emplace_back(TreeNode->val);
    inorder(TreeNode->right);
}

int kthSmallest(TreeNode *root, int k)
{
    inorder(root);

    return v[k - 1];
}

// TODO: Think of a solution in which if the `k` becomes zero return the vector and stop furter recursion using boolean maybe

int main()
{
    TreeNode *root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));

    cout << kthSmallest(root, 1);
}