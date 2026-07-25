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

    int count = 0;
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int ch1 = dfs(root->right);
        int ch2 = dfs(root->left);

        if(root->val >= max(ch1, ch2))
            count ++;
        
        return max({ch1, ch2, root->val});
    }

    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
};