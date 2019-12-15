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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode *> s;
        TreeNode *prev = nullptr;

        while(root  || !s.empty())
        {
            while(root)
            {
                s.push_back(root);
                root = root->left;
            }

            root = s.back();
            s.pop_back();
            if(prev != nullptr && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }

        return true;
        
    }
};