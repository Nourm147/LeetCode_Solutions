/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node *, Node *> mp;
        Node *current = cloneNode(node, mp);
        return current;
    }

    Node *cloneNode(Node *node, unordered_map<Node *, Node *> &map)
    {
        if (node == nullptr)
            return nullptr;

        if (map.find(node) != map.end())
            return map[node];
        Node *newNode = new Node(node->val);
        map.insert({node, newNode});
        for (auto n : node->neighbors)
        {
            newNode->neighbors.push_back(cloneNode(n, map));
        }
        return newNode;
    }
};
