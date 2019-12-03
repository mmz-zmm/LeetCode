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
    /*
    先使用prev记录操作到右最后一个小于x的值的位置，curr记录第一个大于x的值的位置；
    随后，从curr位置开始向后扫描，follow为curr的下一个元素。
    1. 当follow的值大于等于x, 将curr和follow向后移；
    2. 当follw的值小于x,将follow元素移到prev的后面，并且更新prev(向后移动到最新添加的小于x的元素的位置)
    使用curr
    */
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
        {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = &dummy;
        ListNode *curr = prev->next;
        while(curr && curr->val < x)
        {
            curr = curr->next;
            prev = prev->next;
        }

        if(curr)
        {
            ListNode * follow = curr->next;
            while(follow)
            {
                if(follow->val < x)
                {
                    ListNode *tmp = follow;
                    curr->next = follow->next;
                    follow = follow->next;

                    tmp->next = prev->next;
                    prev->next = tmp;
                    prev = prev->next;
                }
                else
                {
                    curr = follow;
                    follow = follow->next;
                }
            }
        }

        return dummy.next;
        
    }
};