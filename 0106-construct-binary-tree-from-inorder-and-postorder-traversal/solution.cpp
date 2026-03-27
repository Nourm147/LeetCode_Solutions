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
    int index;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() <= 1 || index == 0)
        {
            if (inorder.size() == 1)
            {
                index--;
                return new TreeNode(inorder[0]);
            }
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[index]);

        auto it = find(inorder.begin(), inorder.end(), root->val);
        index--;

        if (it == inorder.end())
        {
            return nullptr;
        }

        int i = it - inorder.begin();

        vector<int> v1(inorder.begin(), inorder.begin() + i);
        vector<int> v2(inorder.begin() + i + 1, inorder.end());

        root->right = build(v2, postorder);
        root->left = build(v1, postorder);

        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        index = inorder.size() - 1;
        return build(inorder, postorder);
    }
};


