// ? 94. Binary Tree Inorder Traversal
// ? https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include <iostream>
#include <bits/stdc++.h>

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

class Solution
{
public:
    vector<int> lol;
    void traverseTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return;
        }

        traverseTree(root->left);

        // cout << root->val << " ";
        lol.push_back(root->val);

        traverseTree(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {

        traverseTree(root);

        return lol;
    }
};

int main()
{
    // idk driver code here !
    // TODO: Write driver code.....
}