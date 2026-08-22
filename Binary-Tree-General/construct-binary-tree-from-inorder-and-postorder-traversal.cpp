class Solution {
public:
    // This helper relates only to inorder indices we use postorder only to extract root
    TreeNode* build(int start, int end, vector<int>& postorder, std::unordered_map<int, int>& mapping) {
        if (start > end) return nullptr;

        int root_val = postorder.back(); // Extract root value (last element) (O(1) since using stack)
        postorder.pop_back();

        TreeNode* root = new TreeNode(root_val); // Construct the root based on root val

        int mid = mapping[root_val]; // Lookup in dict where the index is (O(1))

        // Recursively build left and right subtree - BUILD RIGHT FIRST SINCE POSTORDER
        root->right = build(mid + 1, end, postorder, mapping);
        root->left = build(start, mid - 1, postorder, mapping);

        return root; // Return te newly constructed node
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::unordered_map<int, int> mapping; // val : index

        for (int index = 0; index < (int)inorder.size(); ++index) {
            mapping[inorder[index]] = index;
        }

        return build(0, (int)inorder.size() - 1, postorder, mapping); // Call helper function
    }
};
