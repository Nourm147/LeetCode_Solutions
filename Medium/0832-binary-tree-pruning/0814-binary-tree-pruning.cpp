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

    pair<TreeNode*,int> construct(TreeNode* root)
    {
        if(root == nullptr)
            return {nullptr, 0};


        int sum = 0;

        auto p1 = construct(root->left);
        auto p2 = construct(root->right);

        root->left = p1.first, root->right = p2.first;
        
        sum = root->val + p1.second + p2.second ;

        if(sum == 0)
            return {nullptr, 0};
        return {root, sum};
    }

    TreeNode* pruneTree(TreeNode* root) {
        return construct(root).first;
    }
};