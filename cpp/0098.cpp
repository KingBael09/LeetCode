// ? 98. Validate Binary Search Tree
// ? https://leetcode.com/problems/validate-binary-search-tree/description/

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

vector<TreeNode *> v;
void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    v.push_back(root);
    inorder(root->right);
}

bool isValidBST(TreeNode *root)
{
    inorder(root);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i]->val <= v[i - 1]->val)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // TreeNode *root = new TreeNode(2, nullptr, new TreeNode(3));
    // TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    // TreeNode *root = new TreeNode(2, new TreeNode(2), new TreeNode(2));
    TreeNode *root = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));

    if (isValidBST(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}