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

    pair<int, int> maxPath(TreeNode* node){
        if(node == nullptr)
            return {0, INT_MIN};
        pair<int, int> lm = maxPath(node->left);
        pair<int, int> rm = maxPath(node->right);

        int mxConnected = max({lm.first + node->val, rm.first + node->val, node->val});
        int mx = max({lm.second, rm.second, lm.first + node->val + rm.first, mxConnected});
        return {mxConnected, mx};
    }


    int maxPathSum(TreeNode* root) {
        return maxPath(root).second;
    }
};