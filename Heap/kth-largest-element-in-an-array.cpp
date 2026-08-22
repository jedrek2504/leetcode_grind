class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[r];          // Choose last element as pivot
        int p = l;                    // Pointer for elements <= pivot

        // Partition the array
        for (int i = l; i < r; ++i) {
            if (nums[i] <= pivot) {
                std::swap(nums[p], nums[i]);
                p += 1;
            }
        }

        // Place pivot in its correct position
        std::swap(nums[p], nums[r]);

        // Recurse only into the part that contains k
        if (p > k) {
            return quickSelect(nums, l, p - 1, k);
        } else if (p < k) {
            return quickSelect(nums, p + 1, r, k);
        } else {
            return nums[p];       // Found k-th largest
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // Convert k-th largest to index in sorted array (ascending)
        k = nums.size() - k;

        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
