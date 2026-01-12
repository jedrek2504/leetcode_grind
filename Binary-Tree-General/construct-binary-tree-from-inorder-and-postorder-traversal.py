from collections import deque


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        mapping = {}  # val : index

        for index, val in enumerate(inorder):
            mapping[val] = index

        # This helper relates only to inorder indices we use postorder only to extract root
        def build(start, end):
            if start > end:
                return None

            root_val = (
                postorder.pop()
            )  # Extract root value (last element)(O(1) since using stack)

            root = TreeNode(root_val)  # Construct the root based on root val

            mid = mapping[root_val]  # Lookup in dict where the index is (O(1))

            # Recursively build left and right subtree - BUILD RIGHT FIRST SINCE POSTORDER
            root.right = build(mid + 1, end)
            root.left = build(start, mid - 1)

            return root  # Return te newly constructed node

        return build(0, len(inorder) - 1)  # Call helper function
