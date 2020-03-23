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
 单调栈：栈顶到栈底单调递减，当新插入一个值时，与栈顶的元素进行比较，如果大于栈顶元素，在本题的语境下，刚好就是我们要寻找的那个nextLarger，如果不是的话，我们就添加一个0，表示没有找到。
*/
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        using node = pair<int, int>;
        stack<node> st;
        auto i = 0;
        while(head) {
            while(!st.empty() && (head->val > st.top().second)) {
                res[st.top().first] = head->val;
                st.pop();
            }
            st.push({i, head->val});
            i++;
            res.push_back(0);
            head = head->next;
        }

        return res;
    }
};
