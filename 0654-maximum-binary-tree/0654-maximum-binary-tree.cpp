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

    TreeNode* construct(vector<int>& nums, int l, int r){
        if(l > r)
            return nullptr;
        if(l == r)
            return new TreeNode(nums[l]);

        int ind = max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();

        if(ind < nums.size() && ind >= 0){
            TreeNode* node = new TreeNode(nums[ind]);
            node->left = construct(nums, l, ind - 1);
            node->right = construct(nums, ind + 1, r);

            return node;
        }

        return nullptr;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};