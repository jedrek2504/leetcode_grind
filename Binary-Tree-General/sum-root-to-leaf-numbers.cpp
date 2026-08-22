class Solution {
public:
    int dfs(TreeNode* node, int total) {
        if (!node) return 0;

        total = total * 10 + node->val;    // Each recursion we increase the total sum
                                            // e.x Nodes (1) -> (2) and we now handle insert (3)
                                            // we get:
                                            // 12 * 10 + 3 = 123

        // If we got to the leaf return total so far
        if (!node->left && !node->right) {
            return total;
        }

        return dfs(node->left, total) + dfs(node->right, total); // Call both subtrees
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0); // Call dfs helper
    }
};
