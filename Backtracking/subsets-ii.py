class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        nums.sort() # Sort the numbers in-place; it ensures duplicate numbers are next to each other.
        res = [] # [[1, 2, 2], [1, 2] ... ] contains subsets.
        subset = []

        def backtrack(i: int) -> None:
            # Base case
            if i == len(nums):
                res.append(subset.copy())
                return

            # Option 1: Add the number
            subset.append(nums[i])
            backtrack(i + 1)
            subset.pop() # When already visited pop() 

            # Option 2: NEVER include the number
            # Increment i until we are not having the same value
            temp = nums[i]
            while i < len(nums) and nums[i] == temp:
                i += 1
            # If we got here:
            backtrack(i) # We are on next non-duplicate value and we can continue to traverse option2 branch.
            
        backtrack(0)
        return res
