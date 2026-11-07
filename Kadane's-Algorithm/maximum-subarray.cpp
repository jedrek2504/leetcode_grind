class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Define curr and max subarray values with val of first element in the nums
        int max_sub = nums[0];
        int curr_sub = nums[0];

        // Go through every number after the first one (already taken care of)
        for (int i = 1; i < (int)nums.size(); i++) {
            curr_sub = std::max(curr_sub + nums[i], nums[i]); // Whats more beneficial for us? -> to add this number or to take it as is?
            max_sub = std::max(max_sub, curr_sub);            // Update max_sub if found bigger curr subarr
        }

        return max_sub;
    }
};
