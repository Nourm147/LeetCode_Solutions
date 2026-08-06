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

    unordered_map<int, int> mp;
    int n;
    TreeNode* construct(int preS, int preE, int postS,vector<int>& pre,vector<int>& post){
        if(preS>preE)
            return nullptr;
        if(preS == preE)
            return new TreeNode(pre[preS]);

        int left = pre[preS + 1];
        int nodes = mp[left] - postS + 1; // elements in the left subtree

        TreeNode* root = new TreeNode(pre[preS]);

        root->left = construct(preS + 1, preS + nodes, postS, pre, post);

        root->right = construct(preS + nodes + 1, preE, postS + nodes, pre, post);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        n = postorder.size();

        for(int i = 0; i < n; i ++){
            mp[postorder[i]] = i;
        }

        return construct(0, n - 1, 0, preorder, postorder);
    }
};