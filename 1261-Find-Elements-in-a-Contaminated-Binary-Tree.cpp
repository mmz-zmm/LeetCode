/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        root_ = root;
        if (root == nullptr) return;
        queue<TreeNode*> tree;
        root->val = 0;
        tree.push(root);

        TreeNode *curr = nullptr;
        while(!tree.empty()) {
            curr = tree.front();
            tree.pop();
            if (curr->left) {
                curr->left->val = curr->val * 2 + 1;
                tree.push(curr->left);
            }

            if (curr->right) {
                curr->right->val = curr->val * 2 + 2;
                tree.push(curr->right);
            }
        }
    }
    
    // 巧用二进制解法：有一个很有趣的特性，左节点后缀为0，右节点后缀为1，通过带查询数字的二进制表示，能够快速定位
    // 注意这个特性适用的是从1开始的根节点
    //              +1
    //              |
    //       10<----+---> 11
    //       +             +
    //       |             |
    //       |             |
    // 100 <-+-->101  110<-+-->111
   
    bool find(int target) {
        int new_target = target +  1;
        bitset<32> bits(new_target);

        bool found = false;
        TreeNode * curr = root_;

        // bitset用法注意：下标0表示最低位，因此需要反序遍历
        for(int i = bits.size() - 1; i >= 0; --i) {
            if(!found) {
                if(bits[i]) {
                    found = true;
                } 
                continue;
            }

            curr = bits[i] ? curr->right : curr->left;
            if(!curr) {
                return false;
            }
        }
        return true;
    }
private:
    TreeNode *root_;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */