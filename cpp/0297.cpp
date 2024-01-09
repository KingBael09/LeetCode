// ? 297. Serialize and Deserialize Binary Tree
// ? https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x) : val(x), left(NULL), right(NULL) {} //below were manually added
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string serialize(TreeNode *root)
{
    if (!root)
    {
        return "#";
    }
    return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
}

TreeNode *decode(vector<string> &ds, int &i)
{
    if (ds[i] == "#")
    {
        i++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(stoi(ds[i++]));
    node->left = decode(ds, i);
    node->right = decode(ds, i);

    return node;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    vector<string> ds;

    stringstream stream(data);

    string word;

    while (stream >> word)
    {
        ds.push_back(word);
    }

    int i = 0;

    return decode(ds, i);
}

// This is something i don't understand fully
TreeNode *betterDecode(stringstream &stream)
{
    string val = "";
    stream >> val;

    if (val == "#")
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(val));
    root->left = betterDecode(stream);
    root->right = betterDecode(stream);

    return root;
}

TreeNode *betterDeserialize(string data)
{
    if (data.empty())
    {
        return nullptr;
    }
    stringstream stream(data);
    return betterDecode(stream);
}

// This is just for testing
void preOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));

    TreeNode *ans = deserialize(serialize(root));

    preOrder(ans);
}