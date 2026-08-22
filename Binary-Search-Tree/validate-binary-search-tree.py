class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        prev = None

        # Helper function for the dfs
        def dfs(node) -> bool:
            nonlocal prev
            if not node:
                return True # Return True when no node

            if not dfs(node.left):
                return False

            # If prev has been set and prev value is not smaller then cur then invalid BST
            if prev is not None and prev >= node.val:
                return False

            prev = node.val # Set prev to curr node each recursive call

            return dfs(node.right) # Call dfs on right node

        return dfs(root) # return the result of our helper func
