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
    int getMaxHight(TreeNode *node){
        if(node == nullptr)
            return 0;
        
        return 1 + max(getMaxHight(node->left), getMaxHight(node->right));
    }

    int h;

    void place(TreeNode *root, int ind, int j, vector<vector<string>>& results)
    {
        if(root == nullptr)
            return;
        results[ind][j] = to_string(root->val);
        place(root->left, ind + 1, j - ((h - ind - 1 < 0) ? 0 :(1 << (h - ind - 1))), results);
        place(root->right, ind + 1, j + ((h - ind - 1 < 0) ? 0 :(1 << (h - ind - 1))), results);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        h = getMaxHight(root) - 1;
        int n = (1 << (h + 1)) - 1;
        vector<vector<string>> results(h + 1, vector<string> (n));

        place(root, 0, (n - 1) / 2, results);

        return results;
    }
};