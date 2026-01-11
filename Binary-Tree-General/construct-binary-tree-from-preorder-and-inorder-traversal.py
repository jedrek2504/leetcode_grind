class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # Base case:
        # If there are no nodes to construct from (empty traversal),
        # then the subtree is empty.
        if not preorder or not inorder:
            return None

        # PREORDER property:
        # The first element in preorder traversal is ALWAYS the root
        root_val = preorder[0]
        root = TreeNode(root_val)

        # INORDER property:
        # Elements to the LEFT of root_val belong to the left subtree
        # Elements to the RIGHT of root_val belong to the right subtree
        mid = inorder.index(root_val)

        """
        Now we split the traversal arrays into left and right subtrees.

        Example:
        preorder = [3, 9, 20, 15, 7]
        inorder  = [9, 3, 15, 20, 7]

        root = 3
        inorder left  = [9]
        inorder right = [15, 20, 7]

        The size of the left subtree = mid
        So we take the same number of nodes from preorder (after root)
        """

        # LEFT SUBTREE:
        # preorder[1 : mid + 1]
        #   - skip root (index 0)
        #   - take exactly 'mid' elements for left subtree
        # inorder[:mid]
        #   - all nodes before root in inorder
        root.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])

        # RIGHT SUBTREE:
        # preorder[mid + 1:]
        #   - remaining elements after left subtree
        # inorder[mid + 1:]
        #   - all nodes after root in inorder
        root.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])

        # Return the constructed subtree
        return root
