class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        res = [] # [[1, 2], [1, 3], [1, 4]], [2, 3], ...] - Store combs
        comb = [] # Represents combination of length k

        # Backtrack function, start - where to start iterating from
        def backtrack(start: int) -> None:
            # Important, not start == k but actually if comb reaches length of k is our base case
            if len(comb) == k:
                res.append(comb.copy())
                return

            # Iterate through the nums starting from start.
            for num in range(start, n + 1):
                comb.append(num) # Add a num
                backtrack(num + 1) # Start next recursive call with num + 1 to avoid duplciates
                comb.pop() # Backtrack when visited the node

        backtrack(1)  # Call backtrack starting from 1
        return res        
