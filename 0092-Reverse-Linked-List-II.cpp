/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if(head == NULL || m == n)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        for(auto i = 0; i < m - 1; ++i)
        {
            prev = prev->next;
        }

        ListNode *cur = prev->next;
        ListNode *tmp;
        for(auto j = m; j < n; ++j)
        { 
            tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        } 

        return dummy.next;  
    }
};