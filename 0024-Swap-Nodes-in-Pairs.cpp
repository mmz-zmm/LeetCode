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
    ListNode* swapPairs(ListNode* head) {
        // 空链表和只有一个元素的链表，特殊处理
        if(head == NULL || head->next == NULL){
            return head;
        }
        // 使用dummy简化List操作
        ListNode dummy =  ListNode(-1);
        dummy.next = head;
        /*
            dummy--->1--->2--->3--->4--->NULL
               ^     ^    ^
            second   temp first
            
        */
        ListNode *first= dummy.next->next;
        ListNode *second = &dummy;
        ListNode *temp = NULL;  //辅助指针，用于记录first与second的中间节点
        
        // 当有奇数个元素时,到达链表最右端时，second不为空，first眼睛指向了尾后元素，此时也要结束
        while(first){
            temp = second->next;
            second->next = first;
            temp->next = first->next;
            first->next = temp;
            // 此时second肯定不为空，它指向的元素是原temp指向的元素
            second = first->next;
            // 下一个元素不为空,继续进行交换；为空，表明已经到达末尾，无需再交换
            if(second->next){
                first = second->next->next;
            }
            else{
               break; 
            }
        }
        head = dummy.next;
        
        return head;
        
    }
};