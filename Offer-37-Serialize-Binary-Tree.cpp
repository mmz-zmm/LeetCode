/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode *> q;

        auto serializeAdd = [&res](TreeNode *node) {
            res += node ? to_string(node->val) : "null";
            res += ',';
        };

        TreeNode *p = root;
        q.emplace(p);

        while (!q.empty()) {
            p = q.front();
            serializeAdd(p);
            q.pop();
            if (p) {
                q.emplace(p->left);
                q.emplace(p->right);
            }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {

        int n = data.size();
        if (n == 0) {
            return nullptr;
        }
        int start = 0;
        int end = 0;
        auto deserializeNext = [&data, &start, &end]() -> TreeNode * {
            TreeNode *res = NULL;
            end = data.find(',', start);
            if (data[start] != 'n') {
                res = new TreeNode(stoi(data.substr(start, end - start)));
            }
            start = end + 1;
            end = start;
            return res;
        };

        TreeNode *head = deserializeNext();
        TreeNode *p = head;
        queue<TreeNode *> q;
        q.emplace(p);
        TreeNode *left = NULL;
        TreeNode *right = NULL;

        while (!q.empty()) {
            p = q.front();
            q.pop();

            if (p) {
                left = deserializeNext();
                right = deserializeNext();
                p->left = left;
                p->right = right;
                q.emplace(left);
                q.emplace(right);
            }
        }

        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));