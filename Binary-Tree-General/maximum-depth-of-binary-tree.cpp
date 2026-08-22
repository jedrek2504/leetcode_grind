class Solution {
public:
    int maxDepth(TreeNode* root) {
        // If the node does not exist then increment 0
        if (!root) return 0;

        // Call maxDepth functions on left and right branches of root
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + std::max(leftDepth, rightDepth); // return 1 (root height) + the bigger hight of left and right branch
    }
};
