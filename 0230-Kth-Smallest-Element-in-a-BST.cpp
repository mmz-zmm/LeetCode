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
    /*
    使用二叉树的中序遍历，可以得到一个有序的数组。使用count进行计数，当为k时a，返回彼时访问的元素
    */
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> s;
        while(!s.empty() || root){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                TreeNode * top = s.top();
                s.pop();
                count++;
                if(count == k)
                    return top->val;
                root= top->right;
            }
        }
        return 0;
    }
};