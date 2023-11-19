// ? 211. Design Add and Search Words Data Structure
// ? https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class TrieNode
{
private:
    vector<TrieNode *> children;
    bool flag;

public:
    TrieNode()
    {
        flag = false;
        children.resize(26, nullptr);
    }
    bool containsKey(char ch)
    {
        return children[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }
    TrieNode *get(char ch)
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
    vector<TrieNode *> &getChildren()
    {
        return children;
    }
};

class WordDictionary
{
private:
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        auto node = root;
        for (auto ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new TrieNode());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search_node(TrieNode *node, const string &word, int i)
    {
        if (i == word.size())
        {
            return node->isEnd();
        }

        auto ch = word[i];

        if (ch == '.')
        {
            for (auto child : node->getChildren())
            {
                if (child && search_node(child, word, i + 1))
                {
                    return true;
                }
            }

            return false;
        }

        // Otherwise
        if (!node->containsKey(ch))
        {
            return false;
        }

        return search_node(node->get(ch), word, i + 1);
    }

    bool search(string word, int i = 0)
    {
        return search_node(root, word, 0);
    }
};

int main()
{
}