class Solution {
public:
    // We need to call dfs on two nodes at the same time for comparison hence left, right node
    bool dfs(TreeNode* left, TreeNode* right) {
        // If both compared nodes are None then the tree is symetric
        if (!left && !right) return true;
        // If one node is None and the other is not then we cant compare them and tree is not symetric
        if (!left || !right) return false;

        return left->val == right->val               // Check if vals are equal and
            && dfs(left->left, right->right)          // recursively see if corresponding node values are equal as well
            && dfs(left->right, right->left);         // The result is a bool answer
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right); // Call helper function
    }
};
