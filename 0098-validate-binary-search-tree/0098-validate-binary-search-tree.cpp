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

    bool sorted(TreeNode* node, long long &pre){
        if(node == nullptr)
            return true;

        if(!sorted(node->left, pre))
            return false;

        if(pre >= node->val)
            return false;
        
        pre = node->val;

        if(!sorted(node->right, pre))
            return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long pre = -(1LL<<31) - 1;
        return sorted(root, pre);
    }
};