class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        q = deque([root]) 
        res = []

        while q:
            temp = []
            for _ in range(len(q)):
                popped = q.popleft()
                temp.append(popped.val)
                
                if popped.left:
                    q.append(popped.left)
                if popped.right:
                    q.append(popped.right)

            res.append(temp)
            temp = []

        return res
