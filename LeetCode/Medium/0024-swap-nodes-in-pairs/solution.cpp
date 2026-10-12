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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *First = head;
        ListNode *Second = head->next;
        while (Second != nullptr)
        {
            int temp = Second->val;
            Second->val = First->val;
            First->val = temp;
            First = Second->next;
            if (First != nullptr)
            {
                Second = First->next;
            }
            else
            {
                break;
            }
        }
        return head;
    }
};
