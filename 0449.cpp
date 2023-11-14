// ? 449. Serialize and Deserialize BST
// ? https://leetcode.com/problems/serialize-and-deserialize-bst/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "#";
        }

        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode *decode(stringstream &ss)
    {
        string val = "";
        ss >> val;

        if (val == "#")
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(stoi(val));

        root->left = decode(ss);
        root->right = decode(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return NULL;
        }

        stringstream ss(data);

        return decode(ss);
    }
};

// TODO: I Think we could leverage the property of BST being in order to make the encoding more compact

int main()
{
}