// ? 111. Minimum Depth of Binary Tree
// ? https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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

// Very bad method uses too much memory
int minDepth(TreeNode *root)
{
    int ans = 0;
    if (!root)
    {
        return 0;
    }

    deque<TreeNode *> q;

    q.push_back(root);

    while (!q.empty())
    {
        int size = q.size();
        ans++;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop_front();

            if (!node->left && !node->right)
            {
                return ans;
            }

            if (node->left)
            {
                q.push_back(node->left);
            }
            if (node->right)
            {
                q.push_back(node->right);
            }
        }
    }

    return ans;
}

// TODO: Memory can be optimized
// Maybe recursive method can do it better

int main()
{
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    int ans = minDepth(root);

    cout << ans;
}