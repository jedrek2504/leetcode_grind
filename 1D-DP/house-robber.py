class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)

        # If we have at most 2 houses on the street, we can only rob one anyways.
        if n <= 2:
            return max(nums)  # Return the bigger value

        res = 0
        prev2, prev1 = nums[0], max(
            nums[0], nums[1]
        )  # Instead of memo dict use two max_profit vars: prev2 = (i - 2) house , prev1 = (i - 1) house.

        for i in range(2, n):
            res = max(prev1, prev2 + nums[i])
            # Update prev values
            prev2 = prev1
            prev1 = res

        return res
