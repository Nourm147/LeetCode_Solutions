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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticals;

        int pre = head->val;
        head = head->next;
        int ind = 1;
        while(head->next != nullptr){
            if((head->val > pre && head->val > head->next->val) || (head->val < pre && head->val < head->next->val))
                criticals.push_back(ind);
            ind ++;
            pre = head->val;
            head = head->next;
        }

        if(criticals.size() < 2)
            return {-1, -1};

        int mn = criticals[(int)criticals.size() - 1] - criticals[0];
        for(int i = 1; i < criticals.size(); i ++){
            mn = min(mn, criticals[i] - criticals[i - 1]);
        }

        return {mn, criticals[(int)criticals.size() - 1] - criticals[0]};
    }
};