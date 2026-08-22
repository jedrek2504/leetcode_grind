class Solution {
public:
    TreeNode* build(int start, int end, std::deque<int>& preorder, std::unordered_map<int, int>& mapping) {
        // OPTIMIZATION:
        // Instead of creating preorder/inorder slices,
        // we pass only index boundaries (start, end).
        if (start > end) return nullptr;

        // preorder.pop_front() always gives the next root
        // and advances the pointer without copying arrays
        int root_val = preorder.front();
        preorder.pop_front();
        TreeNode* root = new TreeNode(root_val);

        // O(1) inorder split using the hashmap
        int mid = mapping[root_val];

        // Build subtrees only within the valid inorder ranges
        root->left = build(start, mid - 1, preorder, mapping);
        root->right = build(mid + 1, end, preorder, mapping);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // OPTIMIZATION vs O(n^2):
        // Precompute value -> index mapping for inorder traversal.
        // This avoids calling inorder.index(val) which would be O(n) each time.
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < (int)inorder.size(); ++i) {
            mapping[inorder[i]] = i;
        }

        // OPTIMIZATION vs O(n^2):
        // Convert preorder to a deque so we can remove the front in O(1).
        // Using a vector would make erasing the front O(n) due to shifting elements.
        std::deque<int> preorderDeque(preorder.begin(), preorder.end());

        // The entire inorder traversal corresponds to the range [0 .. n-1]
        return build(0, (int)inorder.size() - 1, preorderDeque, mapping);
    }
};
