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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
        {
            return ret;
        }

        vector<TreeNode *> q;
        q.push_back(root);
        
        bool left2right = true;

        while(!q.empty())
        {
            auto sz = q.size();
            vector<int> level;
            for(auto i = 0; i < sz; ++i)
            {
                auto node = q.front();
                if(left2right)
                {
                    level.push_back(node->val);
                }
                else
                {
                    level.insert(level.begin(), node->val);
                }
                q.erase(q.begin());
                if(node->left != nullptr) q.push_back(node->left);
                if(node->right != nullptr) q.push_back(node->right);

            }
            
            ret.push_back(level);
            left2right = !left2right;
        }
        return ret;
        
    }
};