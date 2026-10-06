class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        # Base case
        if not root:
            return False

        # If leaf node return True if path was found (total diff equal to 0)
        if not root.left and not root.right:
            return targetSum - root.val == 0

        targetSum -= root.val  # Each recursion decrement targetSum

        # Perform operations above for both subtrees and see if at least one of them is True
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(
            root.right, targetSum
        )
