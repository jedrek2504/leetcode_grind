class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)  # Extract number of houses

        # Edge case: If there is only one house -> return its value immediately.
        if n == 1:
            return nums[0]

        # Solve linear houses, pass the indexes to make it O(1)
        def helper(start, end) -> int:
            prev1, prev2 = 0, 0  # profit up (i - 1) house, (i - 2) house
            for i in range(start, end):
                profit = max(prev2 + nums[i], prev1)  # Calculate current profit
                prev2, prev1 = prev1, profit  # Update profits for next iterations

            return profit  # Profit stores the best profit so far.

        return max(
            helper(1, n), helper(0, n - 1)
        )  # Call helper without first and last house and take the max (They can't both be robbed)
