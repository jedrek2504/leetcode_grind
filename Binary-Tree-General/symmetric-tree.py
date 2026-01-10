class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # We need to call dfs on two nodes at the same time for comparison hence left, right node
        def dfs(left, right):
            # If both compared nodes are None then the tree is symetric
            if not left and not right:
                return True
            # If one node is None and the other is not then we cant compare them and tree is not symetric
            if not left or not right:
                return False

             
            return (
                left.val == right.val           # Check if vals are equal and
                and dfs(left.left, right.right) # recursively see if corresponding node values are equal as well
                and dfs(left.right, right.left)
            )  # The result is a bool answer

        return dfs(root.left, root.right) # Call helper function
