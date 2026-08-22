class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case
        if (!root) return false;

        // If leaf node return True if path was found (total diff equal to 0)
        if (!root->left && !root->right) {
            return targetSum - root->val == 0;
        }

        targetSum -= root->val; // Each recursion decrement targetSum

        // Perform operations above for both subtrees and see if at least one of them is True
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
