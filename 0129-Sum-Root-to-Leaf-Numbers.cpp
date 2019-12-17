/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {

        return backtrace(root, 0);
    }

    int backtrace(TreeNode *root, int local_sum)
    {
        if(root == nullptr) 
            return 0;

        local_sum = local_sum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            return local_sum;
        }

        auto left  = backtrace(root->left, local_sum);
        auto right = backtrace(root->right, local_sum);
        
        return left + right;
    }
};