class Solution:
    def validPath(
        self, n: int, edges: list[list[int]], source: int, destination: int
    ) -> bool:
        # Edge case - if source and destination are the same - return True
        if source == destination:
            return True

        adj = defaultdict(list)  # {node: [nei,1, nei2 ...], } - Adjecancy list
        visited = set()  # Set to store visited nodes

        # Build an adjacancy list:
        for v1, v2 in edges:
            # Graph is undirected so add both possibilities:
            adj[v1].append(v2)
            adj[v2].append(v1)

        # Iterative dfs
        def dfs(node: int) -> bool:
            q = []  # Dfs
            q.append(node)

            while q:
                popped = q.pop()  # Pop from the queue
                # Go through each neighbour
                for nei in adj[popped]:
                    # If it already has been viisted
                    if nei in visited:
                        continue  # Skip
                    # If a nei is a destination
                    if nei == destination:
                        return True  # We have reached waht we looked for in this dfs.

                    # Otherwise
                    q.append(nei)  # Add a nei to the queue
                    visited.add(nei)  # Mark nei visited so we don't revisit it

            return False  # If we got here and did not return True then it's imposible to reach destination

        return dfs(source)  # Return dfs(source)
