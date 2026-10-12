/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int, int> calculate(TreeNode* node, int &count)
    {
        if(node == nullptr)
            return {0, 0};
        
        auto p1 = calculate(node->left, count);
        auto p2 = calculate(node->right, count);

        int average = (p1.first + p2.first + node->val) / (p1.second + p2.second + 1);

        count += (node->val == average);

        return {p1.first + p2.first + node->val, p1.second + p2.second + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        calculate(root, count);
        return count;
    }
};