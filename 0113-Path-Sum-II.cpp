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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> lists;
        vector<int>  list;

        backtrace(root, sum, lists, list);
        return  lists;
    }

    void backtrace(const TreeNode *root, int sum, vector<vector<int>> &lists, vector<int> &list)
    {   
        if(root == nullptr)
            return;
        list.push_back(root->val);
        if( root->left == nullptr && root->right == nullptr && root->val == sum)
        {
            lists.push_back(list);
        }
        else
        {
            backtrace(root->left, sum - root->val, lists, list);
            backtrace(root->right, sum - root->val, lists, list);
        }
        list.pop_back();
    }
};