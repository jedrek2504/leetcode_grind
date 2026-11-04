class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, (int)nums.size() - 1, nums); // Call helper function on the full nums arr
    }

private:
    // Recursive function that takes l, r (bounds of given subarray)
    TreeNode* helper(int l, int r, vector<int>& nums) {
        // If at any point left pointer is larger than the right one
        if (l > r) {
            return nullptr; // It means that we went out of bounds - return nullptr
        }

        int m = l + (r - l) / 2; // Calculate middle point (doesn't matter if even or odd number of items in array)
        TreeNode* root = new TreeNode(nums[m]); // Construct a root node
        root->left = helper(l, m - 1, nums); // Left subtree is a result of calling recursive function on the left of the current middle.
        root->right = helper(m + 1, r, nums); // Right subtree is a result of calling recursive function on the right of the current middle

        return root; // Return the root
    }
};
