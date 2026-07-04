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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k);
        if(head == nullptr)
            return result;

        ListNode* node = head;
        int count = 1;
        while(node->next != nullptr){
            node = node->next;
            count ++;
        }

        int i = 0;
        while(count > 0){
            int sub = ceil((double)count / k);
            count -= sub;
            k --;

            sub --;
            node = head;

            while(sub --){
                node = node->next;
            }
            result[i] = head;
            head = node->next;
            node->next = nullptr;
            i ++;
        }


        return result;
    }
};
