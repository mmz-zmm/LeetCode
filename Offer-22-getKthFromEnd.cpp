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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *curr = head;
        ListNode *prev = curr;
        while (k-- && prev) {
            prev = prev->next;
        }
        while (prev) {
            prev = prev->next;
            curr = curr->next;
        }

        return curr;
    }
};