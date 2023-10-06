// ? 654. Maximum Binary Tree
// ? https://leetcode.com/problems/maximum-binary-tree/description/

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

TreeNode *helper(TreeNode *root, int start, int end, vector<int> &nums)
{
    if (start >= end)
    {
        return nullptr;
    }

    int cur_max = nums[start];
    int cur_idx = start;
    for (int i = start; i < end; i++)
    {
        if (nums[i] > cur_max)
        {
            cur_max = nums[i];
            cur_idx = i;
        }
    }

    TreeNode *newNode = new TreeNode(cur_max);

    newNode->left = helper(newNode, start, cur_idx, nums);
    newNode->right = helper(newNode, cur_idx + 1, end, nums);

    return newNode;
}

TreeNode *consize(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int max_idx = start;

    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] > nums[max_idx])
        {
            max_idx = i;
        }
    }

    TreeNode *root = new TreeNode(nums[max_idx]);

    root->left = consize(nums, start, max_idx - 1);
    root->right = consize(nums, max_idx + 1, end);

    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return consize(nums, 0, nums.size() - 1);
    // return helper(nullptr, 0, nums.size(), nums);
}

// Better Approach

// TC:O(N) SC:O(N)
TreeNode *constructMaximumBinaryTreeBetter(vector<int> &nums)
{
    stack<TreeNode *> st;

    TreeNode *root = nullptr;
    TreeNode *curr = nullptr;

    for (int i : nums)
    {
        curr = new TreeNode(i);

        while (!st.empty() && st.top()->val < i)
        {
            curr->left = st.top();
            st.pop();
        }

        if (!st.empty())
        {
            st.top()->right = curr;
        }
        else
        {
            root = curr;
        }

        st.push(curr);
    }

    return root;
}

int main()
{
}