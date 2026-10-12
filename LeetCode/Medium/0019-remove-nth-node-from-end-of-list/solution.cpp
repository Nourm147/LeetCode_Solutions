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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        int count = removeRecursive(head, n);
        if (n > count)
        {
            return head->next;
        }
        return head;
    }
    int removeRecursive(ListNode *head, int n)
    {
        if (head->next == nullptr)
        {
            return 0;
        }
        int count = removeRecursive(head->next, n) + 1;
        if (count == n)
        {
            head->next = head->next->next;
        }
        return count;
    }
};
