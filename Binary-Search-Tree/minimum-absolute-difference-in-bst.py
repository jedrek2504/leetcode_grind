class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        prev, res = None, float("inf") # "Global" variables to access from dfs inner func

        # DFS helper function
        def dfs(node):
            # If a passed node is nonexistent - skip
            if node is None:
                return

            dfs(node.left)  # Call dfs on left node

            nonlocal prev, res  # Make nonlocal so that we dont treat these as inner scope vars resulting in an error

            # If prev has been set at least once
            if prev is not None:
                res = min(res, node.val - prev.val) # Update result

            prev = node # Update prev to a current node

            dfs(node.right) # Call dfs on right node with updated prev value

        dfs(root)   # Call the dfs helper function

        return res  # Return a result
