class Solution:
    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
        n = len(edges)  # len(edges) == n (problem statement)

        par = [
            i for i in range(n + 1)
        ]  # Stores parent of i-th node. Initially every node is each own parent ; n + 1 beacuse array is 1 indexed.
        rank = [1] * (n + 1)  # Stores how many nodes point to ith node

        # Find node's parent
        def find(n: int) -> int:
            p = n

            while p != par[p]:
                par[p] = par[par[p]]
                p = par[p]

            return p

        # Union two nodes, return a if union was needed (1/0)
        def union(n1: int, n2: int) -> int:
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return 0
            if rank[p1] < rank[p2]:
                par[p1] = par[p2]  # Smaller tree gets asigned a bigger tree
                rank[p2] += rank[p1]  # Bigger tree's size increases by smaller tree's size
            else:
                par[p2] = par[p1]
                rank[p1] += rank[p2]

            return 1

        # Main loop - go through each pair in edges
        for n1, n2 in edges:
            # If the nodes are already pointing to the same parent then the edge is redundant
            if union(n1, n2) == 0:
                return [
                    n1,
                    n2,
                ]  # Return a redundant edge (From the problem description we can assume it's the first one that we find)
