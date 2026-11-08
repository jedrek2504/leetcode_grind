class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = (int)nums.size() - 1;
        int n = (int)nums.size();

        while (l <= r) {
            int m = l + (r - l) / 2; // Calculate middle element and ensure it doesn't overlow
            // If right element is higher and ensure right nei in bounds
            if (m < (n - 1) && nums[m] < nums[m + 1]) {
                l = m + 1; // Go there
            }
            // If left element is higher and ensure left nei in bounds
            else if (m > 0 && nums[m] < nums[m - 1]) {
                r = m - 1; // Go there instead
            }
            // If none are higher - curr element is larger then neis
            else {
                return m;
            }
        }

        // Not possible but cover all paths:
        return 0;
    }
};
