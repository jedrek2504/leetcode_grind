from collections import deque

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        # Return early if empty input
        if not root:
            return

        q = deque()
        q.append(root)
        res = []

        while q:
            total = 0 # Total of vals for current level
            noOfNodes = len(q) # Number of nodes on current level

            # Go through nodes on each level
            for _ in range(noOfNodes):
                popped = q.popleft() # Pop leftmost val form queue
                total += popped.val # Add its val to a total

                # If node has children add it to queue
                if popped.left:
                    q.append(popped.left)
                if popped.right:
                    q.append(popped.right)

            # To result append an avarage
            res.append(total/noOfNodes)

        return res
