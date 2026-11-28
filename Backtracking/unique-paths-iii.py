class Solution:
    def uniquePathsIII(self, grid: list[list[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        seen = set()  # Visited coords in curr path
        to_visit = 0  # How many non obstacle cells are there in a grid

        # Find the start coords and count to_visit cells
        for r in range(ROWS):
            for c in range(COLS):
                # For every non obstacle cell
                if grid[r][c] != -1:
                    if grid[r][c] == 1:
                        start = (r, c)  # Remember the starting value
                    to_visit += 1  # Increment to_visit

        def backtrack(r: int, c: int) -> int:
            # Bounds and seen first
            if not (0 <= r < ROWS) or not (0 <= c < COLS) or (r, c) in seen:
                return 0
            # If cell is an obstacle
            if grid[r][c] == -1:
                return 0  # Return nothing
            # BASE CASE: If a cell is a destination and we've visited every non obstacle cell
            if grid[r][c] == 2:
                return (
                    1 if len(seen) == to_visit - 1 else 0
                )  # seen never adds destination cell so to_visit - 1.

            seen.add((r, c))  # Add to seen

            paths = 0  # Declare paths
            # Go through every direction on a given node
            for dr, dc in dirs:
                paths += backtrack(r + dr, c + dc)  # Call recursively

            seen.remove(
                (r, c)
            )  # After we went through all neis we can remove it from the current path

            return paths

        return backtrack(*start)  # Run backtrack on unpacked row, col starting position
