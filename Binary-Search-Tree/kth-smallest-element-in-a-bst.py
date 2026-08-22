class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        counter = 0
        res = None

        def dfs(node):
            nonlocal counter, res
            if not node or res is not None:
                return

            dfs(node.left)

            counter += 1
            if counter == k:
                res = node.val
                return

            dfs(node.right)

        dfs(root)
        return res
