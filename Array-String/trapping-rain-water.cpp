class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int max_l = height[l], max_r = height[r];

        int total = 0;

        while (l < r) {
            // Increment pointer based on smaller max_val
            if (max_l <= max_r) {
                l = l + 1;
                max_l = std::max(max_l, height[l]);   // Update maxes
                total += std::max(0, std::min(max_l, max_r) - height[l]);  // Add to total based on moved pointer
            } else {
                r = r - 1;
                max_r = std::max(max_r, height[r]);
                total += std::max(0, std::min(max_l, max_r) - height[r]);
            }
        }

        return total;
    }
};
