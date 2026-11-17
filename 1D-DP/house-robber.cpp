class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // If we have at most 2 houses on the street, we can only rob one anyways.
        if (n <= 2) {
            return *max_element(nums.begin(), nums.end()); // Return the bigger value
        }

        int res = 0;
        // Instead of memo dict use two max_profit vars: prev2 = (i - 2) house , prev1 = (i - 1) house.
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            res = max(prev1, prev2 + nums[i]);
            // Update prev values
            prev2 = prev1;
            prev1 = res;
        }

        return res;
    }
};
