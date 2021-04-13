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
    int INF = 1e5 + 9;
    int ans = INF;
    TreeNode *pre = NULL;
    int minDiffInBST(TreeNode *root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }

        inorder(root->left);

        if (pre) {
            ans = min(ans, root->val - pre->val);
        }
        pre = root;

        inorder(root->right);
    }