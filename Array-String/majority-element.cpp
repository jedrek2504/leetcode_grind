class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0]; // Set initial candidate to first element
        int count = 0; // Initial count is set to 0

        // Iterate thorugh each number
        for (int num : nums) {
            // If at the start of iteration a count is == 0 then assign new candidate
            if (count == 0) {
                candidate = num;
            }
            // If current number is a candidate
            if (num == candidate) {
                count += 1; // Increment num's counter
            } else {
                count -= 1; // Decrement num's counter
            }
        }

        return candidate; // Whatever candidate ends up being is the answer
    }
};
