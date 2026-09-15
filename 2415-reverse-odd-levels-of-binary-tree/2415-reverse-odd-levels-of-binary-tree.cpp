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

    TreeNode* reverse(TreeNode* node, int level, vector<vector<int>>& lv){
        if(node == nullptr)
            return node;

        if(level % 2 == 1){
            node->val = lv[level].back();
            lv[level].pop_back();
        }

        reverse(node->left, level + 1, lv);
        reverse(node->right, level + 1, lv);

        return node;
    }

    void construct(TreeNode* node, int level, vector<vector<int>>& lv)
    {
        if(node == nullptr)
            return;

        if(level >= lv.size())
            lv.push_back({});
        lv[level].push_back(node->val);

        construct(node->left, level + 1, lv);
        construct(node->right, level + 1, lv);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<int>> levelValues;
        construct(root, 0, levelValues);
        return reverse(root, 0, levelValues);
    }
};