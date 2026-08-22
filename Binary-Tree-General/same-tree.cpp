class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are None then True
        if (!p && !q) return true;

        // If both nodes are present and their values are equal
        if (p && q && p->val == q->val) {
            // Only then call recursively for left and right branches of tree
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false; // If we got here then the tree is not the same
    }
};
