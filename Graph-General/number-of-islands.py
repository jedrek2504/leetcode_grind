class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # Extract rows and columns
        ROWS = len(grid)
        COLS = len(grid[0])
        seen = set()  # hashset to keep visited nodes
        islands = 0  # No of islands

        def bfs(r, c):
            dirs = [(-1, 0), (0, -1), (0, 1), (1, 0)]  # All 4 directions
            q = deque()  # deque to store coordinates of nodes to be visited
            q.append((r, c))  # append current coors to the queue
            seen.add((r, c))  # mark current coordinates as seen

            while q:
                row, col = q.popleft()  # Pop coordinates for deque

                # For each direction
                for dr, dc in dirs:
                    r, c = row + dr, col + dc  # Compute new coordinates

                    # If new coordinates are not in bounds or coordinates have been visited or the node is not an island
                    if (
                        r not in range(ROWS)
                        or c not in range(COLS)
                        or ((r, c) in seen)
                        or grid[r][c] != "1"
                    ):
                        continue  # Skip

                    # Else append to the queue and the hashmap
                    q.append((r, c))
                    seen.add((r, c))

        # Main loop - iterate over every element and if its an island perform bfs
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1" and (r, c) not in seen:
                    bfs(r, c)
                    islands += 1  # increment island number

        return islands
