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
class BSTIterator {
public:
    vector<int> inOrder;
    int ind;

    void build(TreeNode* node){
        if(node == nullptr)
            return;
        build(node->left);
        inOrder.push_back(node->val);
        build(node->right);
    }

    BSTIterator(TreeNode* root) {
        build(root);
        ind = -1;
    }
    
    int next() {
        ind ++;
        return inOrder[ind];
    }
    
    bool hasNext() {
        return (ind + 1 < inOrder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */