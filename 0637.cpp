// ? 637. Average of Levels in Binary Tree
// ? https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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

vector<double> averageLevel(TreeNode *root)
{
    vector<double> ans;
    deque<TreeNode *> q;

    q.push_back(root);

    while (!q.empty())
    {
        int size = q.size();
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop_front();

            if (node->left != nullptr)
            {
                q.push_back(node->left);
            }
            if (node->right != nullptr)
            {
                q.push_back(node->right);
            }

            sum = sum + node->val;
        }

        ans.push_back(sum / size);
    }

    return ans;
}

// TODO: There exist a method in which there is no need to nest loops of wile and for

int main()
{
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    vector<double> ans = averageLevel(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}