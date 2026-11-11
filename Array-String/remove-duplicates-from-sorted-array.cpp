class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0; // Set the left pointer on the place where the last element was inserted in-place
        int r = 1; // Set the right pointer initially on second position ; we will increment it until the L and R values differ

        // Iterate until we reach the end of an array
        while (r < n) {
            // If L and R are different
            if (nums[l] != nums[r]) {
                l = l + 1; // Prepare a place to put R (new distinct value)
                nums[l] = nums[r]; // Put the value in-place
            }

            // Each iteration increment R pointer
            r += 1;
        }

        return l + 1; // L is incremented each time we add  a new distinct number, but it's an index so +1
    }
};
