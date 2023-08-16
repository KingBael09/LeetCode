// ? 102. Binary Tree Level Order Traversal
// ? https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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

void traverseTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    traverseTree(root->left);

    cout << root->val << " ";

    traverseTree(root->right);
}

vector<vector<int>> levelOrder(TreeNode *root)
{

    vector<vector<int>> ans;

    if (root == nullptr)
    {
        return ans;
    }

    deque<TreeNode *> q; // This would have worked even if we have used a queue

    q.push_back(root); // entry

    while (!q.empty())
    {
        vector<int> currentLevel;
        int len = q.size();

        for (int i = 0; i < len; i++)
        {
            TreeNode *current = q.front();
            q.pop_front();

            currentLevel.push_back(current->val);

            if (current->left != nullptr)
            {
                q.push_back(current->left);
            }
            if (current->right != nullptr)
            {
                q.push_back(current->right);
            }
        }

        ans.push_back(currentLevel);
    }

    return ans;
}

// TODO: Memory usage could be optimized ig
// There exist a method which has nested loops of while and for
int main()
{

    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(17)));
    // TreeNode *root = nullptr;

    // traverseTree(root);

    vector<vector<int>> ans = levelOrder(root);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}