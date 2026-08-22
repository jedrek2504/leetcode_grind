class Solution {
public:
    // Preorder helper
    void preorder(TreeNode* node, vector<TreeNode*>& order) {
        if (!node) return;

        // First middle then left and then right
        order.push_back(node);
        preorder(node->left, order);
        preorder(node->right, order);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> order;

        preorder(root, order); // Populate order arr

        // Go through the order arr
        for (int i = 1; i < (int)order.size(); ++i) {
            // Keep track of prev and curr node in order arr
            TreeNode* prev = order[i - 1];
            TreeNode* curr = order[i];

            prev->left = nullptr; // Make left branches null
            prev->right = curr; // Connect branches
        }

        // We do not return anything
    }
};
