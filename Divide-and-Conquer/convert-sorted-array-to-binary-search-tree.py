class Solution:
    def sortedArrayToBST(self, nums: list[int]) -> TreeNode | None:
        # Recursive function that takes l, r (bounds of given subarray)
        def helper(l: int, r: int) -> TreeNode | None:
            # If at any point left pointer is larger than the right one
            if l > r:
                return None  # It means that we went out of bounds - return None

            m = (
                l + r
            ) // 2  # Calculate middle point (doesn't matter if even or odd number of items in array)
            root = TreeNode(nums[m])  # Construct a root node
            root.left = helper(
                l, m - 1
            )  # Left subtree is a result of calling recursive function on the left of the current middle.
            root.right = helper(
                m + 1, r
            )  # Right subtree is a result of calling recursive function on the right of the current middle

            return root  # Return the root

        return helper(0, len(nums) - 1)  # Call helper function on the full nums arr
