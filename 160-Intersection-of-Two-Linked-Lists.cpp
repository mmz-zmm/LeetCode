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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<int *> address;

        ListNode *p1 = headA;
        while (p1) {
            address.insert(&p1->val);
            p1 = p1->next;
        }

        ListNode *p2 = headB;
        while (p2) {
            if (address.find(&p2->val) != address.end()) {
                return p2;
            }
            p2 = p2->next;
        }
        return nullptr;
    }

    // p1和p2从A、B开始分别向后遍历，遇到结尾后交换位置（p1指向B, p2指向A）,等到相等时，刚好位置为相交点
    // why: A = a + c; B = b + c;
    // p1 = a + c + b; p2 = b + c + a;
    // 由此可看到同时移动p1,p2一定会在交点处相遇
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2) {
            p1 = (p1 == nullptr) ? headB : p1->next;
            p2 = (p2 == nullptr) ? headA : p2->next;
        }

        return p1;
    }
};