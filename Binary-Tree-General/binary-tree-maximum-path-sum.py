class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = float("-inf")

        def dfs(node):
            nonlocal max_sum

            if not node:
                return 0

            # Get best branch sums (ignore negatives)
            left = max(dfs(node.left), 0)
            right = max(dfs(node.right), 0)

            # Path that passes through this node
            current = node.val + left + right

            # Update global maximum
            max_sum = max(max_sum, current)

            # Return best single branch (non-spliting path) to parent (so that he can )
            return node.val + max(left, right)

        dfs(root)
        return max_sum
