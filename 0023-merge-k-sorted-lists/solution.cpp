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
#include <bits/stdc++.h>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        ListNode *list = new ListNode();
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        ListNode *start = list;
        while (!pq.empty())
        {
            pair<int, int> a = pq.top();
            pq.pop();
            start->next = new ListNode(a.first);
            start = start->next;
            ListNode *node = lists[a.second];
            if (node != nullptr)
            {
                pq.push({node->val, a.second});
                lists[a.second] = node->next;
            }
        }

        return list->next;
    }
};
