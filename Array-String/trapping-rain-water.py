class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n - 1
        max_l, max_r = height[l], height[r]

        total = 0

        while l < r:
            # Increment pointer based on smaller max_val
            if max_l <= max_r:
                l = l + 1
                max_l = max(max_l, height[l])   # Update maxes
                total += max(0, min(max_l, max_r) - height[l])  # Add to total based on moved pointer
            else:
                r = r - 1
                max_r = max(max_r, height[r])
                total += max(0, min(max_l, max_r) - height[r])

        return total
