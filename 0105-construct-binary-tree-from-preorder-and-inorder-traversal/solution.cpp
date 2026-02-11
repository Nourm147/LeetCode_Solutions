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
#include <bits/stdc++.h>
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    int index = 0;
    map<int, int> inMap;
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        if (start == end)
        {
            index++;
            return new TreeNode(preorder[index - 1]);
        }
        if (start > end)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[index]);
        int ind = inMap[preorder[index]];

        index++;

        root->left = build(preorder, inorder, start, ind - 1);
        root->right = build(preorder, inorder, ind + 1, end);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap.insert({inorder[i], i});
        }

        return build(preorder, inorder, 0, preorder.size() - 1);
    }
};
