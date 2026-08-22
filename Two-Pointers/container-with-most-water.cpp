class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize l, r pointers
        int l = 0, r = height.size() - 1;
        int max_area = 0;

        while (l < r) {
            // Max area is a distance between pointers * smaller value
            max_area = std::max(max_area, (r - l) * std::min(height[l], height[r]));

            // Update pointers based on which value is less
            if (height[r] > height[l]) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        return max_area;
    }
};
