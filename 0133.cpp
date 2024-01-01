// ? 133. Clone Graph
// ? https://leetcode.com/problems/clone-graph/description/

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph_bfs(Node *node)
{
    if (!node)
    {
        return node;
    }

    unordered_map<Node *, Node *> map = {{node, new Node(node->val)}};

    deque<Node *> q = {node};

    while (!q.empty())
    {
        auto old_curr = q.front();

        q.pop_front();

        for (auto old_adj : old_curr->neighbors)
        {
            // if not present in map
            if (map.find(old_adj) == map.end())
            {
                map[old_adj] = new Node(old_adj->val);
                q.push_back(old_adj);
            }

            map[old_curr]->neighbors.push_back(map[old_adj]);
        }
    }

    return map[node];
}

// --------------

unordered_map<Node *, Node *> mp;

Node *cloneGraph(Node *node)
{
    if (!node)
    {
        return node;
    }

    const auto new_curr = new Node(node->val);

    mp[node] = new_curr;

    for (const auto &adj : node->neighbors)
    {
        if (mp.find(adj) != mp.end())
        {
            // We find the node
            new_curr->neighbors.push_back(mp[adj]);
        }
        else
        {
            new_curr->neighbors.push_back(cloneGraph(adj));
        }
    }

    return new_curr;
}