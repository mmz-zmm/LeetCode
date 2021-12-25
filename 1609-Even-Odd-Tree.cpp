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
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> q;

        q.emplace(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                int val = node->val;
                if (level % 2 == val % 2) {
                    return false;
                }

                if ((level % 2 == 0 && val <= prev) ||
                    (level % 2 == 1 && val >= prev)) {
                    return false;
                }
                prev = val;
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
            level++;
        }

        return true;
    }
};