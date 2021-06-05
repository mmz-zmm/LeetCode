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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dumy(0, head);
        ListNode *fast = dumy.next;
        ListNode *slow = &dumy;
        ListNode *marked = nullptr;
        while (fast) {
            if (fast->val == val) {
                marked = fast;
                slow->next = fast->next;
                fast = fast->next;
                delete marked;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return dumy.next;
    }
};