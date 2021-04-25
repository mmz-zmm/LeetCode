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
        TreeNode *res = pre;
        inorderTranversal(root);
        return res->right;
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
};