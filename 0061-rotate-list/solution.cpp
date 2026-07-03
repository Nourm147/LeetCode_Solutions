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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr || head->next == nullptr)
            return head;
        ListNode* node = head;
        int count = 1;
        while(node->next != nullptr){
            node = node->next;
            count ++;
        }
        node->next = head;

        count -= (k % count);

        while (count--){
            node = node->next;
        }

        head = node->next;
        node->next = nullptr;
        return head;
    }
};
