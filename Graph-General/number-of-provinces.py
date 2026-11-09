class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        parent = [i for i in range(n)]  # [0, 1, 2, 3, ... , n] - parents pointers
        rank = [
            1
        ] * n  # [1, 1, 1, ... , 1] - initial rank for each city (every city is it's own parent)
        res = n  # Number of provinces - initially set to individual cities, each union will -1 it.

        # Find a node's parent
        def find(node: int) -> int:
            par = node

            # While curr node is not it's parent
            while par != parent[par]:
                parent[par] = parent[
                    parent[par]
                ]  # Optimisation: set parent to grandparent if possible
                par = parent[par]  # Set the curr node to it's parent

            return par  # Return parent (noide that search ends up)

        # Union 2 provinces based on their size (rank)
        def union(n1: int, n2: int) -> int:
            p1, p2 = find(n1), find(n2)  # Find parents of n1 and n2

            # If parents match
            if p1 == p2:
                return 0  # They're already in the same province

            # Else union them

            # If first node rank is bigger
            if rank[p1] > rank[p2]:
                parent[p2] = parent[p1]  # Union second node to first one.
                rank[p1] += rank[p2]  # Update the rank
            else:
                parent[p1] = parent[p2]
                rank[p2] += rank[p1]

            return 1  # If we got here we performed an union

        # Extract edges from 2d matrix
        for r in range(n):
            # Iterate over top half - no reason to search the bottom since dupliacted info
            for c in range(r + 1, n):
                # If a pair of cities (edge) is not connected to each other (excluding the same cities)
                if r == c or isConnected[r][c] == 0:
                    continue  # Skip
                # Else union cities
                res -= union(
                    r, c
                )  # Union returns 0 or 1, if 1 then it's succesful so overall number of not connected cities decreases.

        return res
