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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 空链表
        if(!head) 
            return head;
        /*
        双指针法, p2----p1之间相差距离为n+1, 当p1移到链表末端nullptr时，p2移到待删除元素的前一位
        */
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *first = dummy;
        ListNode *second = dummy;
        
        /*
        之所以是n+1, 是因为要找的必须是待删的前一位元素，不然无法改变指针指向，跳过待删的元素
        */
        int interval = n + 1;
        while( interval-- > 0){
            first = first->next;
        }
        
        while(first){
            first = first->next;
            second = second->next;
        }
        // 释放待删除元素的内存
        ListNode *tmp = second->next;
        second->next = tmp->next;
        delete tmp;
        
        head = dummy->next;
        //释放dummy
        delete dummy;
        
        return head;
    }
};