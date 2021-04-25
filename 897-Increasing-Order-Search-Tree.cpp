/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *pre;
    TreeNode *increasingBST(TreeNode *root) {
        pre = new TreeNode(-1);
        TreeNode *p = pre;
        inorderTranversal(root);
        TreeNode *res = p->right;
        delete p;
        return res;
    }

    void inorderTranversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inorderTranversal(root->left);
        root->left = nullptr;
        pre->right = root;
        pre = root;
        inorderTranversal(root->right);
    }

    TreeNode *increasingBSTNonRecursive(TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *res = dummy;

        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                p = p->left;
            } else {
                auto top = st.top();
                st.pop();
                p = top->right;
                top->left = nullptr;
                dummy->right = top;
                dummy = top;
            }
        }
        return res->right;
    }
};