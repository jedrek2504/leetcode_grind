class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # If the node is None then we skip
        if not root:
            return None

        # Swap right and left Nodes
        root.left, root.right = root.right, root.left

        # Recursively call the function on left and right nodes
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root  # Return the node (not the value!)
