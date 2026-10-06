class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        order = []

        # Preorder helper
        def preorder(node):
            if not node:
                return

            # First middle then left and then right
            order.append(node)
            preorder(node.left)
            preorder(node.right)

        preorder(root)  # Populate order arr

        # Go through the order arr
        for i in range(1, len(order)):
            # Keep track of prev and curr node in order arr
            prev = order[i - 1]
            curr = order[i]

            prev.left = None  # Make left branches null
            prev.right = curr  # Connect branches

        # We do not return anything
