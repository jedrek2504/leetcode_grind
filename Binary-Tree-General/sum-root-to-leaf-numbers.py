class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def dfs(node, total):
            if not node:
                return 0

            total = total * 10 + node.val   # Each recursion we increase the total sum
                                            # e.x Nodes (1) -> (2) and we now handle insert (3)
                                            # we get:
                                            # 12 * 10 + 3 = 123

            # If we got to the leaf return total so far
            if (not node.left and not node.right):
                return total

            return dfs(node.left, total) + dfs(node.right, total) # Call both subtrees

        return dfs(root, 0) # Call dfs helper
