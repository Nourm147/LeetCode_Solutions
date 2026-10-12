/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {

        if(head == nullptr)
            return nullptr;

        ListNode *slow = head, *fast = head, *sPre = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            sPre = slow;
            slow = slow->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        root->right = sortedListToBST(slow->next);
        if(sPre != nullptr){
            sPre->next = nullptr;
            root->left = sortedListToBST(head);
        }

        return root;
    }
};