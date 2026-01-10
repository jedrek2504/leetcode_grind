class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # If the node does not exist then increment 0
        if not root:
            return 0

        # Call maxDepth functions on left and right branches of root
        leftDepth = self.maxDepth(root.left)
        rightDepth = self.maxDepth(root.right)

        return 1 + max(
            leftDepth, rightDepth
        )  # return 1 (root height) + the bigger hight of left and right branch
