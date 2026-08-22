class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Initialize l, r pointers
        l, r = 0, len(height) - 1
        max_area = 0

        while l < r:
            # Max area is a distance between pointers * smaller value
            max_area = max(max_area, (r - l) * min(height[l], height[r]))

            # Update pointers based on which value is less
            if height[r] > height[l]:
                l += 1
            else:
                r -= 1

        return max_area
