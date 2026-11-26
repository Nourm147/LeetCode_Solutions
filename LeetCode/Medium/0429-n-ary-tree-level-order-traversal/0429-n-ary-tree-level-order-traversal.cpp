/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr)
            return {};
            
        vector<vector<int>> result;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            if(top.second + 1 > result.size())
                result.push_back({});
            result[top.second].push_back(top.first->val);

            for(Node* node : top.first->children)
            {
                if(node != nullptr)
                    q.push({node, top.second + 1});
            }
        }

        return result;
    }
};