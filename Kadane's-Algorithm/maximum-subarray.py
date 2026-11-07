class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        # Define curr and max subarray values with val of first element in the nums
        max_sub = nums[0]
        curr_sub = nums[0]

        # Go through every number after the first one (already taken care of)
        for i in range(1, len(nums)):
            curr_sub = max(
                curr_sub + nums[i], nums[i]
            )  # Whats more beneficial for us? -> to add this number or to take it as is?
            max_sub = max(
                max_sub, curr_sub
            )  # Update max_sub if found bigger curr subarr

        return max_sub
