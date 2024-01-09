// ? 129. Sum Root to Leaf Numbers
// ? https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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

vector<string> ans;

void helper(TreeNode *root, string s)
{
    if (!root)
    {
        return;
    }

    s.append(to_string(root->val));

    if (!root->left && !root->right)
    {
        ans.push_back(s);
        return;
    }

    helper(root->left, s);
    helper(root->right, s);
    s.pop_back();
}

int sumNumbersWithString(TreeNode *root)
{
    helper(root, "");

    int sum = 0;

    for (auto i : ans)
    {
        sum += stoi(i);
    }

    return sum;
}

// Better method without using strings

int betterHelper(TreeNode *root, int sum)
{
    if (!root)
    {
        return 0;
    }

    sum = (sum * 10) + root->val;

    if (!root->left && !root->right)
    {
        return sum;
    }

    return betterHelper(root->left, sum) + betterHelper(root->right, sum);
}

int sumNumbers(TreeNode *root)
{
    return betterHelper(root, 0);
}

int main()
{
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    // TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << sumNumbersWithString(root);
}