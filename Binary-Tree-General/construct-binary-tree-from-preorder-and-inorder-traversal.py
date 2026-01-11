from collections import deque


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        # OPTIMIZATION vs O(n²):
        # Precompute value -> index mapping for inorder traversal.
        # This avoids calling inorder.index(val) which would be O(n) each time.
        mapping = {}
        for i in range(len(inorder)):
            mapping[inorder[i]] = i

        # OPTIMIZATION vs O(n²):
        # Convert preorder to a deque so we can remove the first element in O(1).
        # Using a list would make pop(0) O(n) due to shifting elements.
        preorder = deque(preorder)

        def build(start, end):
            # OPTIMIZATION:
            # Instead of creating preorder/inorder slices,
            # we pass only index boundaries (start, end).
            if start > end:
                return None

            # preorder.popleft() always gives the next root
            # and advances the pointer without copying arrays
            root = TreeNode(preorder.popleft())

            # O(1) inorder split using the hashmap
            mid = mapping[root.val]

            # Build subtrees only within the valid inorder ranges
            root.left = build(start, mid - 1)
            root.right = build(mid + 1, end)

            return root

        # The entire inorder traversal corresponds to the range [0 .. n-1]
        return build(0, len(inorder) - 1)
