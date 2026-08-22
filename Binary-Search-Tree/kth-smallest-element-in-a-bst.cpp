class Solution {
public:
    void dfs(TreeNode* node, int k, int& counter, int& res, bool& found) {
        if (!node || found) return;

        dfs(node->left, k, counter, res, found);

        counter += 1;
        if (counter == k) {
            res = node->val;
            found = true;
            return;
        }

        dfs(node->right, k, counter, res, found);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0, res = -1;
        bool found = false;
        dfs(root, k, counter, res, found);
        return res;
    }
};
