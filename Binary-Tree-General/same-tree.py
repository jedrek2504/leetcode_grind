class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # If both nodes are None then True
        if not p and not q:
            return True

        # If both nodes are present and their values are equal
        if p and q and p.val == q.val:
            # Only then call recursively for left and right branches of tree
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

        return False  # If we got here then the tree is not the same
