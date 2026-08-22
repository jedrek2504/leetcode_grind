class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sort the array to introduce two pointers
        vector<vector<int>> ans;

        // Because two pointers must fit to the right of the a
        for (int a = 0; a < (int)nums.size() - 2; ++a) {
            // Do not use the same a value as before
            if (a > 0 && nums[a] == nums[a - 1]) continue;

            int l = a + 1, r = nums.size() - 1; // Initiate l, r pointers

            while (l < r) {
                vector<int> triplets = {nums[a], nums[l], nums[r]}; // Declare triplets
                int s = triplets[0] + triplets[1] + triplets[2]; // s - sum of triplets

                // If sum is greater then 0 it means that we need to decrease the value -> shift right pointer
                if (s > 0) {
                    r -= 1;
                } else if (s < 0) {
                    l += 1;
                // If sum == 0 we have one of the results
                } else {
                    ans.push_back(triplets);

                    // We only need to shift one of the pointers the other one will be shifted by the code above
                    l += 1;
                    // Shift it until value is different to avoid duplicates
                    while (l < r && nums[l] == nums[l - 1]) {
                        l += 1;
                    }
                }
            }
        }

        return ans;
    }
};
