// ?700. Search in a Binary Search Tree
// ? https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/

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

// Inefficient Method
TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *current = root;
    TreeNode *result = NULL;

    while (current)
    {
        if (current->val == val)
        {
            result = current;
            break;
        }

        else if (val > current->val)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    return result;
}

TreeNode *searchBSTFaster(TreeNode *root, int val)
{
    TreeNode *current = root;

    while (current && current->val != val)
    {

        if (val > current->val)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    return current;
}

int main()
{
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));

    int target = 2;

    TreeNode *result = searchBST(root, target);

    cout << result->val << " " << result->left->val << " " << result->right->val;
}
