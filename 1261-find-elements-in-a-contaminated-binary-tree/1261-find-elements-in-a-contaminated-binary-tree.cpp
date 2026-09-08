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
class FindElements {
public:

    set<int> values;

    void recover(TreeNode* root){ 
        values.insert(root->val);

        if(root->left != nullptr)
        {
            root->left->val = 2 * root->val + 1;
            recover(root->left);
        }
        if(root->right != nullptr)
        {
            root->right->val = 2 * root->val + 2;
            recover(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        recover(root);
    }
    
    bool find(int target) {
        return (values.count(target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */