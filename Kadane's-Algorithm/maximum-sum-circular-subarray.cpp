class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Initialize all variables to first element
        int total = nums[0];
        int curr_max = nums[0];
        int global_max = nums[0];
        int curr_min = nums[0];
        int global_min = nums[0];

        // Iterate through the array starting from second element
        for (int i = 1; i < (int)nums.size(); i++) {
            total += nums[i]; // Calculate total
            // Kadane's algorithm - max subarray
            curr_max = std::max(curr_max + nums[i], nums[i]);
            global_max = std::max(global_max, curr_max);
            // Kadane's algorithm - min subarray
            curr_min = std::min(curr_min + nums[i], nums[i]);
            global_min = std::min(global_min, curr_min);
        }

        // Edge case: If every number is negative
        if (global_max < 0) {
            return global_max; // Return this number, because default return value will return zero
        }

        return std::max(
            global_max, total - global_min
        ); // The trick is here: Either we take global_max (subarray is in the middle of an array), or (total - global_min) (subarray is acrros circular transition)
    }
};
