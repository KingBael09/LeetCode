// ? 648. Replace Words
// ? https://leetcode.com/problems/replace-words/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
private:
    vector<Node *> children;

    string s = "";

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
    void setString(string word)
    {
        s = word;
    }
    string getString()
    {
        return s;
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

        node->setString(word);
    }

    string longestPrefix(string prefix)
    {
        auto node = root;

        int idx = 0, sz = prefix.size();

        while (idx < sz)
        {
            if (!node->containsKey(prefix[idx]))
            {
                return prefix;
            }

            node = node->get(prefix[idx]);
            idx++;

            auto cur_str = node->getString();

            if (cur_str != "")
            {
                return cur_str;
            }
        }

        return prefix;
    }
};

string replaceWords(vector<string> &dictionary, string sentence)
{
    Trie T;

    for (auto str : dictionary)
    {
        T.insert(str);
    }

    stringstream ss(sentence);

    string word;

    string ans = "";

    while (ss >> word)
    {
        ans += T.longestPrefix(word) + " ";
    }

    ans.pop_back();

    return ans;
}

int main()
{
    vector<string> dictionary = {"cat", "bat", "rat"};

    unordered_map<int, int> mp;
}