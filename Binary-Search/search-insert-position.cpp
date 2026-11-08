class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;

        // Iterate until right pointer overlaps the left pointer
        while (l <= r) {
            int m = l + (r - l) / 2; // Calculate middle index

            // If we found our target -> return it's index
            if (nums[m] == target) {
                return m;
            }
            // If target is larger than our number - target is in the right half
            if (nums[m] < target) {
                l = m + 1; // Shift left pointer
            }
            // If target is smaller than our number - target is in the left half
            else if (nums[m] > target) {
                r = m - 1; // Shift right pointer
            }
        }
        // If we got here it means the target is not present and the l poiter contains index where our number should go (because it's past r pointer)
        return l;
    }
};
