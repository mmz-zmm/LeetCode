/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {

        using Index = map<int, vector<int>>;

        map<int, Index> col_index;

        function<void(TreeNode *, const pair<int, int>)> dfs =
            [&](TreeNode *node, const pair<int, int> pos) {
                if (!node) {
                    return;
                }

                auto &row_index = col_index[pos.second];
                row_index[pos.first].push_back(node->val);

                dfs(node->left, make_pair(pos.first + 1, pos.second - 1));
                dfs(node->right, make_pair(pos.first + 1, pos.second + 1));
            };

        dfs(root, make_pair(0, 0));

        vector<vector<int>> res;

        for (auto &[_, row_index] : col_index) {

            vector<int> col;

            for (auto &[_, vec] : row_index) {
                sort(vec.begin(), vec.end());
                copy(vec.begin(), vec.end(), back_inserter(col));
            }
            res.emplace_back(std::move(col));
        }

        return res;
    }
};