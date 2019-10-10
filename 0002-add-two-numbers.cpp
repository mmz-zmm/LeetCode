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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    #ifdef VERSION_1   
        ListNode* head = nullptr;
        ListNode *curr = nullptr;

        int carry {0};
        while(l1 != nullptr || l2 != nullptr || carry!= 0)
        {
            int var1 =  (l1 == nullptr)? 0:l1->val;
            int var2 = (l2 == nullptr)? 0:l2->val;
            carry += (var1 + var2);
            auto node = new ListNode(carry % 10);
            carry /= 10;
            if(head == nullptr){
                head = node;
                curr = node;
            }
            else
            {
                curr->next = node;
                curr = node;
            }
            l1 = (l1->next == nullptr)? nullptr : l1->next;
            l2 = (l2->next == nullptr)? nullptr : l2->next;
        }
        return head;
        
    }
    #endif

    #ifdef VERSION_2
        ListNode *p1 = l1, *p2 = l2;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *curr = dummyHead;
        int carry = 0;
        while( p1 || p2){
            int a = p1 ? p1->val : 0;
            int b = p2 ? p2->val : 0;
            int sum = (a + b + carry);
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            
            curr = curr->next;
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
        }
        curr->next = carry ? new ListNode(1): nullptr;
        ListNode *ret = dummyHead->next;
        delete dummyHead;
        return ret;
    #endif
};