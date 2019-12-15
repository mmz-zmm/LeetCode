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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) 
            return ret;

        vector<TreeNode *> q;
        q.push_back(root);
        int level = 0;
        while(!q.empty())
        {
            auto sz = q.size();
            ret.push_back(vector<int>());
            for(auto i = 0; i < sz; ++i)
            {
                auto t = q.front();
                q.erase(q.begin());
                ret[level].push_back(t->val);
                if(t->left) q.push_back(t->left);
                if(t->right) q.push_back(t->right); 
            }
            ++level;
        }
        return ret;
        
    }
};