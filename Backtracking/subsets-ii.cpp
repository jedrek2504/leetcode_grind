class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sort the numbers in-place; it ensures duplicate numbers are next to each other.
        vector<vector<int>> res; // [[1, 2, 2], [1, 2] ... ] contains subsets.
        vector<int> subset;

        backtrack(0, nums, subset, res);
        return res;
    }

private:
    void backtrack(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        // Base case
        if (i == (int)nums.size()) {
            res.push_back(subset);
            return;
        }

        // Option 1: Add the number
        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset, res);
        subset.pop_back(); // When already visited pop() 

        // Option 2: NEVER include the number
        // Increment i until we are not having the same value
        int temp = nums[i];
        while (i < (int)nums.size() && nums[i] == temp) {
            i++;
        }
        // If we got here:
        backtrack(i, nums, subset, res); // We are on next non-duplicate value and we can continue to traverse option2 branch.
    }
};
