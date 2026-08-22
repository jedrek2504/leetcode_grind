class Solution {
public:
    void dfs(TreeNode* node, TreeNode*& prev, int& res) {
        // If a passed node is nonexistent - skip
        if (node == nullptr) return;

        dfs(node->left, prev, res);  // Call dfs on left node

        // If prev has been set at least once
        if (prev != nullptr) {
            res = std::min(res, node->val - prev->val); // Update result
        }

        prev = node; // Update prev to a current node

        dfs(node->right, prev, res); // Call dfs on right node with updated prev value
    }

    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = nullptr;
        int res = INT_MAX;

        dfs(root, prev, res);   // Call the dfs helper function

        return res;  // Return a result
    }
};
