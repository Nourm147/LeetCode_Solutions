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

    bool valid = true;
    int Check(TreeNode* root){
        if(root == nullptr)
            return 0;

        int left = Check(root->left) + 1;
        int right = Check(root->right) + 1;

        if(abs(left - right) > 1)
            valid = false;

        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        Check(root);
        return valid;
    }
};