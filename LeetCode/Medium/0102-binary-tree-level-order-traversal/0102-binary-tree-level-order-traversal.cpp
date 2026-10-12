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

    int hight(TreeNode *node)
    {
        if(node == nullptr)
            return 0;
        return max(hight(node->left), hight(node->right)) + 1;
    }
    void construct(TreeNode* node, int ind, vector<vector<int>> &result){
        if(node == nullptr)
            return;
        result[ind].push_back(node->val);
        construct(node->left, ind + 1, result);
        construct(node->right, ind + 1, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result (hight(root));
        construct(root, 0, result);
        return result;
    }
};