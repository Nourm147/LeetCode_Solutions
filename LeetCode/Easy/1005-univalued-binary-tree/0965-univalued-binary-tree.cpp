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
    bool isValid(TreeNode *node, int val){
        if(node == nullptr)
            return true;
        if(node->val != val)
            return false;

        if(!isValid(node->left, val) || !isValid(node->right, val))
            return false;
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        return isValid(root, root->val);
    }
};