 class Solution {
public:
    // This functions whole purpose is to calculate the max_path we submit as &
    int dfs(TreeNode* node, int& max_path){
        if(!node) return 0;
        
        // Call dfs on left/right subtrees and ignore negative values
        int left = std::max(dfs(node->left, max_path), 0);
        int right = std::max(dfs(node->right, max_path), 0);

        // Calculate max_path from current "root" node with splitting
        int current = node->val + left + right;

        // Check if its bigger then global max_path if so -> update
        max_path = std::max(max_path, current);

        // For further recursion we pass max_path without splitting so choose better branch
        return node->val + std::max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN; // Set initial max value to lowest possible

        dfs(root, max_path); // Call recursive function
        
        return max_path;
    }
};
