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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> s;
        vector<int> ret;
        while(root != NULL || !s.empty())
        {
            for(; root != NULL ; root= root->left)
            {
                s.push_back(root);
            }
            ret.push_back(s.back()->val);
            root = s.back()->right;
            s.pop_back();
        }

        return ret;
    }
};