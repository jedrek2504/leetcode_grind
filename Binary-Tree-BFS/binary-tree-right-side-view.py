from collections import deque


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # Empty -> return early
        if not root:
            return []

        # Use deque for BFS
        q = deque()
        q.append(root)

        res = []  # res arr to store final results

        # level order traversal - we go layer by layer
        while q:
            res.append(q[-1].val)  # Add rightmost element form current level

            # Go through the current's level nodes and add its children from left to right. (It will be done on a "snapshot" of q length, meaning if we add elements to q inside loop it wont affect how many times the inner loop will execute)
            for _ in range(len(q)):
                popped = q.popleft()

                if popped.left:
                    q.append(popped.left)
                if popped.right:
                    q.append(popped.right)

        return res
