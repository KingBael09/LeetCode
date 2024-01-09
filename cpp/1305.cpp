// ? 1305. All Elements in Two Binary Search Trees
// ? https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

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

void travel(TreeNode *root, vector<int> &res)
{
    if (root)
    {
        travel(root->left, res);
        res.push_back(root->val);
        travel(root->right, res);
    }
    return;
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    travel(root1, res);
    travel(root2, res);
    sort(res.begin(), res.end()); // inplace_merge can also be used here

    return res;
}

vector<int> getAllElements2(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    travel(root1, res);
    int sz = res.size();
    travel(root2, res);
    inplace_merge(res.begin(), res.begin() + sz, res.end());

    return res;
}

int main()
{
    TreeNode *root1 = new TreeNode(2, new TreeNode(1), new TreeNode(4));
    TreeNode *root2 = new TreeNode(1, new TreeNode(0), new TreeNode(3));

    for (auto i : getAllElements2(root1, root2))
    {
        cout << i << " ";
    }
}