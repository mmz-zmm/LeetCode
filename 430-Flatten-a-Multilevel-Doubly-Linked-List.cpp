/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flatten(Node *head) {

        Node *tail = NULL;
        dfs(tail, head);

        return head;
    }

    void dfs(Node *&tail, Node *curr) {
        if (curr == NULL) {
            return;
        }

        Node *next = curr->next;
        if (tail != NULL) {
            tail->next = curr;
            curr->prev = tail;
        }

        tail = curr;

        dfs(tail, curr->child);
        curr->child = NULL;
        dfs(tail, next);
    }
};