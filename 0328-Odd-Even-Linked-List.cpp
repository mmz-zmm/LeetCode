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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || 
        head->next == nullptr || 
        head->next->next == nullptr){
            return head;
        }

        ListNode *tail1 = head;
        ListNode *head2 = head->next;
        ListNode *tail2 = head2;

        ListNode *pCurr = head2->next;
        ListNode *pNext = nullptr;
        bool isFirst = true;
        while(pCurr){
            pNext = pCurr->next;
            if(isFirst) {
                tail1->next = pCurr;
                tail1 = pCurr;
            }else{
                tail2->next = pCurr;
                tail2 = pCurr;
            }
            isFirst = !isFirst;
            pCurr = pNext;
        }
        tail1->next = head2;
        tail2->next = nullptr;
        return head;
    }
};