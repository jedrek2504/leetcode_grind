class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // If the node is None then we skip
        if (!root) return nullptr;

        // Swap right and left Nodes
        std::swap(root->left, root->right);

        // Recursively call the function on left and right nodes
        invertTree(root->left);
        invertTree(root->right);

        return root; // Return the node (not the value!)
    }
};
