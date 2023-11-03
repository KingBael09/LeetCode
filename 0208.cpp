// ? 208. Implement Trie (Prefix Tree)
// ? https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
private:
    vector<Node *> children;
    bool flag = false;

public:
    Node()
    {
        children = vector<Node *>(26, nullptr);
    }

    bool containsKey(char ch)
    {
        return children[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node)
    {
        children[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return children[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        auto node = root;
        for (auto ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        auto node = root;
        for (auto ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }

            node = node->get(ch);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {

        auto node = root;

        for (auto ch : prefix)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }

        return true;
    }
};

int main()
{
    auto T = new Trie();

    T->insert("apple");
    cout << T->search("apple");
    cout << T->search("app");
}