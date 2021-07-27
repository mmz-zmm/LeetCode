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
    int findSecondMinimumValue(TreeNode *root) {

        int mini_val = root->val;
        int res = -1;

        function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            if (!node) {
                return;
            }
            if (node->val != mini_val) {
                if (res == -1) {
                    res = node->val;
                } else {
                    res = min(res, node->val);
                }
                return;
            }
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        return res;
    }
};