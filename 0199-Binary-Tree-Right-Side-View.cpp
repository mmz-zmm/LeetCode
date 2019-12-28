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
    vector<int> rightSideView(TreeNode* root) {
        auto ret = vector<int>();
        if(root == nullptr) return ret;
        auto q = queue<const TreeNode*>();
        q.push(root);
        while(!q.empty())
        {
            auto sz = q.size();
            for(auto i = 0; i < sz;++i)
            {
                auto n = q.front();
                q.pop();
                if(n->left != nullptr) 
                    q.push(n->left);
                if(n->right != nullptr)
                    q.push(n->right);
                if(i == sz - 1)
                    ret.push_back(n->val);

            }
        }
        return ret;

    }
};