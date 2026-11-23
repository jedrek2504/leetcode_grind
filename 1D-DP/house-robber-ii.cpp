class Solution {
private:
    // Solve linear houses, pass the indexes to make it O(1)
    int helper(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0; // profit up (i - 1) house, (i - 2) house
        int profit = 0;
        for (int i = start; i < end; i++) {
            profit = max(prev2 + nums[i], prev1); // Calculate current profit
            prev2 = prev1; // Update profits for next iterations
            prev1 = profit;
        }

        return profit; // Profit stores the best profit so far.
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size(); // Extract number of houses

        // Edge case: If there is only one house -> return its value immediately.
        if (n == 1) {
            return nums[0];
        }

        // Call helper without first and last house and take the max (They can't both be robbed)
        return max(helper(nums, 1, n), helper(nums, 0, n - 1));
    }
};
