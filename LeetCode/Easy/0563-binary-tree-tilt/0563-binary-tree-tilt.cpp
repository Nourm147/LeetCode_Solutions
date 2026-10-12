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
    pair<int, int> findT(TreeNode* root) {
        if(root == nullptr)
            return {0, 0};

        pair<int, int> p1 = findT(root->left);
        pair<int, int> p2 = findT(root->right);

        return {abs(p1.second - p2.second) + p1.first + p2.first, p1.second + p2.second + root->val};
    }

    int findTilt(TreeNode* root) {
        return findT(root).first;
    }
};