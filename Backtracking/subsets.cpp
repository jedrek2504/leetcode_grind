class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; // [[1, 2, 3], [1, 2], ...]
        vector<int> subset;

        backtrack(0, nums, subset, res);
        return res;
    }

private:
    void backtrack(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        // If we are at leaf-node level:
        if (i == (int)nums.size()) {
            res.push_back(subset); // Make a snapshot of subset
            return; // Return to the previous caller (We get here when on leaf node)
        }

        // If we are not on a leaf node level
        // Option 1: Add a num
        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset, res);

        // Option 2: Don't add a num
        subset.pop_back();
        backtrack(i + 1, nums, subset, res);
        return; //  Return to the previous caller - We get here when we visited lef node pair and need to access the "next" one
    }
};
