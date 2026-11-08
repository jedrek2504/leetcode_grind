class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        # Initialize all variables to first element
        total = curr_max = global_max = curr_min = global_min = nums[0]

        # Iterate through the array starting from second element
        for i in range(1, len(nums)):
            total += nums[i]  # Calculate total
            # Kadane's algorithm - max subarray
            curr_max = max(curr_max + nums[i], nums[i])
            global_max = max(global_max, curr_max)
            # Kadane's algorithm - min subarray
            curr_min = min(curr_min + nums[i], nums[i])
            global_min = min(global_min, curr_min)

        # Edge case: If every number is negative
        if global_max < 0:
            return global_max  # Return this number, because default return value will return zero

        return max(
            global_max, total - global_min
        )  # The trick is here: Either we take global_max (subarray is in the middle of an array), or (total - global_min) (subarray is acrros circular transition)
