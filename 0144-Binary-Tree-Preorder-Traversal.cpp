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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if( root == nullptr)
            return ret;
        
        vector<TreeNode*> q;
        TreeNode * tmp = nullptr;
        while(!q.empty() || root)
        {
            while(root)
            {
                q.push_back(root);
                ret.push_back(root->val);
                root= root->left;     
            }
            tmp = q.back();
            q.pop_back();
            root = tmp->right;
        }

        return ret;
    }
};