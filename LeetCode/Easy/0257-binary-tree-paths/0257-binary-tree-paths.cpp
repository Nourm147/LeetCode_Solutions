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

    string toStr(vector<int> &v){
        string result;
        result += to_string(v[0]);
        for(int i = 1; i < v.size(); i ++){
            result += "->";
            result += to_string(v[i]);
        }

        return result;
    }

    void construct(vector<string>& result, vector<int> &v, TreeNode* root){

        if(root != nullptr)
        {
            v.push_back(root->val);
            
            if(root->left == nullptr && root->right == nullptr){
                if(!v.empty())
                result.push_back(toStr(v));
            }

            if(root->left != nullptr)
                construct(result, v, root->left);
            if(root->right != nullptr)
                construct(result, v, root->right);
            
            v.pop_back();
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> v;

        construct(result, v, root);

        return result;
    }
};