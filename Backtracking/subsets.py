class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        res = [] # [[1, 2, 3], [1, 2], ...]
        subset = []

        def backtrack(i: int) -> None:
            # If we are at leaf-node level:
            if i == len(nums):
                res.append(subset.copy()) # Make a snapshot of subset
                return # Return to the previous caller (We get here when on leaf node)

            # If we are not on a leaf node level
            # Option 1: Add a num
            subset.append(nums[i]) 
            backtrack(i + 1)

            # Option 2: Don't add a num
            subset.pop()
            backtrack(i + 1)
            return #  Return to the previous caller - We get here when we visited lef node pair and need to access the "next" one

        backtrack(0)
        return res
