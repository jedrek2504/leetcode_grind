class Solution {
public:
    // Helper function for the dfs (prev passed by reference since C++ has no closures over locals)
    bool dfs(TreeNode* node, TreeNode*& prev) {
        if (!node) return true; // Return True when no node

        if (!dfs(node->left, prev)) return false;

        // If prev has been set and prev value is not smaller then cur then invalid BST
        if (prev != nullptr && prev->val >= node->val) return false;

        prev = node; // Set prev to curr node each recursive call

        return dfs(node->right, prev); // Call dfs on right node
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return dfs(root, prev); // return the result of our helper func
    }
};
